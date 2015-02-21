#include "quarkgameloader.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include <iostream>


QuarkGameContainer* container;

static int sdlGameThreadCallback(void* data){
    container->init((EngineSettings*)data);
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "GameContainer initialized. Running game...");
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
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "SDL Init successful. Creating game container...");
    container = new QuarkGameContainer();
}

QuarkGameLoader::QuarkGameLoader()
{
}

void QuarkGameLoader::loadGame(QuarkGame* g, EngineSettings* settings)
{
    preInit();
    container->setGame(g);
    gameThread = SDL_CreateThread(sdlGameThreadCallback, "gameThread", settings);
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "GameThread started successfully.");
    // wait for game thread to terminate
    int threadStatus;
    SDL_WaitThread(gameThread, &threadStatus);
    if(threadStatus != 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "GameThread failed to finish successfully. Error code: %d .", threadStatus);
    }
}

QuarkGameLoader::~QuarkGameLoader()
{
    delete container;
    SDL_Quit();
}

