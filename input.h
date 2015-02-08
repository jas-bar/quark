#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL.h>

class Input
{
private:
    SDL_Event event;
    std::map<SDL_Keycode, bool> keyState;
    Sint32 mouseX, mouseY;
    std::map<Uint8, bool> mouseState;
    bool quitRequested;

public:
    Input();
    void update();
    bool isQuitRequested();

    bool isKeyDown(SDL_Keycode key);
    bool isMouseDown(Uint8 button);
    Sint32 getMouseX();
    Sint32 getMouseY();

    ~Input();
};

#endif // INPUT_H
