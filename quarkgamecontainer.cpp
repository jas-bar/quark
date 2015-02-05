#include "quarkgamecontainer.h"

QuarkGameContainer::QuarkGameContainer()
{

}

void QuarkGameContainer::setGame(QuarkGame *g)
{
    this->game = g;
}

void QuarkGameContainer::init()
{
    idealFrameDuration = (Uint32)(1000 / maxFPS);
    window = SDL_CreateWindow("Quark Engine pre-pre-pre-alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    game->init();
    input.reset(new Input());
}

void QuarkGameContainer::render()
{
    game->render();
}

void QuarkGameContainer::update()
{
    input->update();
    if(input->isQuitRequested()){
        running = false;
    }
    game->update(input.get());
}

bool QuarkGameContainer::isRunning()
{
    return running;
}

void QuarkGameContainer::tickStart()
{
    tickStartTime = SDL_GetTicks();
}

void QuarkGameContainer::tickEnd()
{
    Uint32 tickEndTime = SDL_GetTicks();
    Uint32 realFrameDuration = tickEndTime - tickStartTime;

    if(realFrameDuration < idealFrameDuration){
        SDL_Delay(idealFrameDuration - realFrameDuration);
    }
}

QuarkGameContainer::~QuarkGameContainer()
{
    SDL_DestroyWindow(window);
}

