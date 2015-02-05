#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL.h>

class Input
{
private:
    SDL_Event event;
    std::map<int, bool> keyState;
    Sint32 mouseX, mouseY;
    std::map<int, bool> mouseState;
    bool quitRequested;

public:
    Input();
    void update();
    bool isQuitRequested();

    ~Input();
};

#endif // INPUT_H
