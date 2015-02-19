#include "input.h"
#include <SDL.h>

Input::Input()
{
    quitRequested = false;
}

void Input::update()
{
    while(SDL_PollEvent(&event)){
        std::vector<InputListener*> listenerList = listeners[event.type];

        for(auto it = listenerList.begin(); it != listenerList.end(); ++it){
            InputListener* listener = (*it);
            listener->onEvent(&event);
        }
    }
}

void Input::registerListener(SDLEventType eventType, InputListener* listener)
{
    listeners[eventType].push_back(listener);
}

Input::~Input()
{
    for(auto mapIt = listeners.begin(); mapIt != listeners.end(); ++mapIt){
        std::pair<SDLEventType, std::vector<InputListener*>> pair = (*mapIt);
        for(auto listIt = pair.second.begin(); listIt != pair.second.end(); ++listIt){
            InputListener* listener = (*listIt);
            delete listener;
        }
    }
}



bool Keyboard::isKeyDown(SDL_Keycode key)
{
    return keyState[key];
}

void Keyboard::onEvent(SDL_Event* event)
{
    if(event->type == SDL_KEYDOWN){
        keyState[event->key.keysym.sym] = true;
    } else if(event->type == SDL_KEYUP){
        keyState[event->key.keysym.sym] = false;
    }
}


void Mouse::onEvent(SDL_Event* event)
{
    if(event->type == SDL_MOUSEMOTION){
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }

    if(event->type == SDL_MOUSEBUTTONDOWN)
        mouseState[event->button.button] = true;

    if(event->type == SDL_MOUSEBUTTONUP)
        mouseState[event->button.button] = false;
}

Sint32 Mouse::getMouseX()
{
    return mouseX;
}

Sint32 Mouse::getMouseY()
{
    return mouseY;
}
