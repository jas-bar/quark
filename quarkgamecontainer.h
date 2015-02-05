#ifndef QUARKGAMECONTAINER_H
#define QUARKGAMECONTAINER_H

#include <memory>
#include <SDL.h>
#include "quarkgame.h"

class QuarkGameContainer
{
private:
    std::unique_ptr<Input> input;
    QuarkGame* game;
    SDL_Window* window;
    Uint32 tickStartTime;
    Uint32 maxFPS, idealFrameDuration;
    bool running;
public:
    QuarkGameContainer();
    void setGame(QuarkGame* g);
    void init();
    void render();
    void update();
    bool isRunning();
    void tickStart();
    void tickEnd();
    ~QuarkGameContainer();
};

#endif // QUARKGAMECONTAINER_H
