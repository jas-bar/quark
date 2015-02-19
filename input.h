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
    void onEvent(SDL_Event* event);
    ~Keyboard();

};

typedef Sint32 SDLMouseCoordinates;

class Mouse : InputListener {
private:
    SDLMouseCoordinates mouseX, mouseY;
    std::map<Uint8, bool> mouseState;
public:
    void onEvent(SDL_Event* event);
    bool isMouseDown(Uint8 button);
    Sint32 getMouseX();
    Sint32 getMouseY();
};

typedef Uint32 SDLEventType;

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
