#include "quarkgameloader.h"
#include <SDL.h>
#include <SDL_log.h>
#include <iostream>

static int sdlGameThreadCallback(void* data){
    QuarkGameContainer* container = static_cast<QuarkGameContainer*>(data);
    container->init();
    while(container->isRunning()){
        container->tickStart();
        container->update();
        container->render();
        container->tickEnd();
    }
    return 0;
}

void QuarkGameLoader::preInit()
{
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL Init error: %s.", SDL_GetError());
    }
    container.reset(new QuarkGameContainer());
}

QuarkGameLoader::QuarkGameLoader()
{
}

void QuarkGameLoader::loadGame(QuarkGame* g)
{
    preInit();
    container->setGame(g);
    gameThread = SDL_CreateThread(sdlGameThreadCallback, "gameThread", container.get());
}

QuarkGameLoader::~QuarkGameLoader()
{
    int threadStatus;
    SDL_WaitThread(gameThread, &threadStatus);
    if(threadStatus != 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "GameThread failed to finish successfully. Error code: %d .", threadStatus);
    }
    SDL_Quit();
}

