#include "quarkgamecontainer.h"

QuarkGameContainer::QuarkGameContainer()
{
    running = true;
    maxFPS = 60;
}

void QuarkGameContainer::setGame(QuarkGame *g)
{
    this->game = g;
}

void QuarkGameContainer::init()
{
    input.reset(new Input());
    idealFrameDuration = (Uint32)(1000 / maxFPS);
    window = SDL_CreateWindow("Quark Engine pre-pre-pre-alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    game->init();
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
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}

