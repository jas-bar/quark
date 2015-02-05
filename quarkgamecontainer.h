#ifndef QUARKGAMECONTAINER_H
#define QUARKGAMECONTAINER_H

#include <SDL.h>
#include "quarkgame.h"

class QuarkGameContainer
{
private:
    QuarkGame* game;
    SDL_Window* window;
public:
    QuarkGameContainer();
    void setGame(QuarkGame* g);
    void init();
    void render();
    void update();
    ~QuarkGameContainer();
};

#endif // QUARKGAMECONTAINER_H
