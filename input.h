#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "inputlistener.h"

class Keyboard : public InputListener {
private:
    std::map<SDL_Keycode, bool> keyState;
public:
    Keyboard() {}

    /**
     * @brief Returns state of desired key on the Keyboard
     * @param key The desired key on the keyboard
     * @return True if the key is pressed, false otherwise
     */
    bool isKeyDown(SDL_Keycode key);

    /**
     * @brief <b>DO NOT USE!</b> Called internally.
     * @param event SDL event received from the engine
     */
    void onEvent(SDL_Event* event) override;

    ~Keyboard() {}

};

typedef Sint32 SDLMouseCoordinates;

/**
 * @brief Interface to mouse
 */
class Mouse : public InputListener {
private:
    SDLMouseCoordinates mouseX, mouseY;
    std::map<Uint8, bool> mouseState;
public:
    Mouse() {}

    /**
     * @brief <b>DO NOT USE!</b> Called internally.
     * @param event SDL event received from the engine
     */
    void onEvent(SDL_Event* event) override;

    /**
     * @brief
     * @param button Mouse button index in SDL
     * @return True if specified button is down(pressed), otherwise false
     */
    bool isMouseDown(Uint8 button);

    /**
     * @brief Returns X coordinate of mouse
     * @return X coordinate of mouse
     *
     * Coordinates are the same as in SDL, so [0; 0] should be the upper left corner of the window
     * and [windowWidth; windowHeight] should be the lower right corner of the window.
     */
    Sint32 getMouseX();

    /**
     * @brief Returns Y coordinate of mouse
     * @return Y coordinate of mouse
     *
     * Coordinates are the same as in SDL, so [0; 0] should be the upper left corner of the window
     * and [windowWidth; windowHeight] should be the lower right corner of the window.
     */
    Sint32 getMouseY();

    ~Mouse() {}
};

typedef Uint32 SDLEventType;

typedef Sint32 SDLJoyAxisValue;

/**
 * @brief Represents a single GameController
 * Represents one GameController. Periodically receives updates of status from GameControllerManager(automatically..)
 */
class GameController : public InputListener {
private:
    int sdlIndex;
    SDL_GameController* controller;
    std::map<Uint8, bool> buttons;
    std::map<Uint8, SDLJoyAxisValue> axes;
public:
    /**
     * @brief <b>DO NOT USE!</b> Called internally. Creates game controller from SDL joystick index
     * @param sdlIndex Index of GameController in SDL
     */
    GameController(int sdlIndex);

    /**
     * @brief <b>DO NOT USE!</b> Called internally.
     * @param event SDL event received from the engine
     */
    void onEvent(SDL_Event* event);

    /**
     * @brief True if button is pressed
     * @param button Index of button in SDL
     * @return True if specified button is pressed, otherwise false
     */
    bool isButtonDown(Uint8 button);

    /**
     * @brief Returns value of axis.
     * @param axis Index of axis in SDL
     * @return Value of specified axis
     */
    SDLJoyAxisValue getAxisValue(Uint8 axis);

    ~GameController();
};

class Input;

/**
 * @brief Interface to game controllers/joysticks
 */
class GameControllerManager {
private:
    std::vector<GameController> controllers;

    void addGameController(Input* input, SDL_JoystickID sdlJoystickIndex);
public:
    /**
     * @brief <b>DO NOT USE!</b> Called internally.
     * @param input The input interface
     */
    void init(Input* input);

    /**
     * @brief Returns count of available controllers
     * @return Count of game controllers which are plugged in and usable with SDL_GameController interface
     */
    int getControllerCount();

    /**
     * @brief Returns pointer to a GameController object
     * @param num Index of desired controller
     * @return Pointer to GameController object, which is periodically updated with the latest device state
     */
    GameController* getController(int num);
};

/**
 * @brief This class provides interface to input devices
 * It consists of Mouse, Keyboard and a GameControllerManager.
 * Functionality can be extended using an InputListener.
 */
class Input
{
private:
    SDL_Event event;
    std::map<SDLEventType, std::vector<InputListener*>> listeners;
    Keyboard* keyboard;
    Mouse* mouse;
    GameControllerManager* gameControllerManager;
    bool quitRequested;
public:
    Input();

    /**
     * @brief <b>DO NOT USE!</b>Called from the game loop to read input devices status
     */
    void update();

    /**
     * @brief Registers an InputListener to be notified about specified event type
     * @param eventType Type of event to be notified about
     * @param listener The listener to notify
     */
    void registerListener(SDLEventType eventType, InputListener* listener);

    /**
     * @brief getKeyboard
     * @return The Keyboard interface
     */
    Keyboard* getKeyboard();

    /**
     * @brief getMouse
     * @return The Mouse interface
     */
    Mouse* getMouse();

    /**
     * @brief getControllerManager
     * @return  Game controller(aka joystick) interface
     */
    GameControllerManager* getControllerManager();

    ~Input();
};



#endif // INPUT_H
