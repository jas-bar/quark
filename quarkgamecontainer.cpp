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
    window = SDL_CreateWindow("Quark Engine pre-pre-pre-alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    game->init();
}

void QuarkGameContainer::render()
{
    game->render();
}

void QuarkGameContainer::update()
{
    game->update();
}

QuarkGameContainer::~QuarkGameContainer()
{

}

