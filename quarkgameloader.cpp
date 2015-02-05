#include "quarkgameloader.h"
#include <SDL.h>
#include <SDL_log.h>

static int sdlGameThreadCallback(void* data){
    QuarkGameContainer* container = static_cast<QuarkGameContainer*>(data);
    while(container->isRunning()){
        container->tickStart();
        container->update();
        container->render();
        container->tickEnd();
    }
    return 0;
}

void quarkgameloader::preInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL Init error: %s.", SDL_GetError());
    }
    container.reset(new QuarkGameContainer());
}

quarkgameloader::quarkgameloader()
{
}

void quarkgameloader::loadGame(QuarkGame* g)
{
    preInit();
    container->setGame(g);
    gameThread = SDL_CreateThread(sdlGameThreadCallback, "gameThread", container.get());
}

quarkgameloader::~quarkgameloader()
{
    int threadStatus;
    SDL_WaitThread(gameThread, &threadStatus);
    if(threadStatus != 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "GameThread failed to finish successfully. Error code: %d .", threadStatus);
    }
}

