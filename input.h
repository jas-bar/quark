#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <memory>
#include <vector>
#include <SDL.h>
#include "inputlistener.h"

class Keyboard : InputListener {
private:
    std::map<SDL_Keycode, bool> keyState;
public:
    Keyboard();
    bool isKeyDown(SDL_Keycode key);
    void onEvent(SDL_Event* event) override;
    ~Keyboard();

};

typedef Sint32 SDLMouseCoordinates;

class Mouse : InputListener {
private:
    SDLMouseCoordinates mouseX, mouseY;
    std::map<Uint8, bool> mouseState;
public:
    void onEvent(SDL_Event* event) override;
    bool isMouseDown(Uint8 button);
    Sint32 getMouseX();
    Sint32 getMouseY();
};

typedef Uint32 SDLEventType;

typedef Sint32 SDLJoyAxisValue;

class GameController : InputListener {
private:
    int sdlIndex;
    SDL_GameController* controller;
    std::map<Uint8, bool> buttons;
    std::map<Uint8, SDLJoyAxisValue> axes;

public:
    GameController(int sdlIndex);
    void onEvent(SDL_Event* event);

    bool isButtonDown(Uint8 button);
    SDLJoyAxisValue getAxisValue(Uint8 axis);
};

class Input;

class GameControllerManager {
private:
    std::vector<GameController> controllers;

    void addGameController(Input* input, SDL_JoystickID sdlJoystickIndex);
public:
    void init(Input* input);
    int getControllerCount();
    GameController* getController(int num);
};

class Input
{
private:
    SDL_Event event;
    std::map<SDLEventType, std::vector<InputListener*>> listeners;

    bool quitRequested;

public:
    Input();
    void update();
    void registerListener(SDLEventType eventType, InputListener* listener);
    ~Input();
};



#endif // INPUT_H
