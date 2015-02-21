#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include <SDL2/SDL_events.h>

class InputListener
{
public:
    virtual void onEvent(SDL_Event* event) = 0;
};

#endif // INPUTLISTENER_H
