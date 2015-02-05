#include "quarkgame.h"
#include <iostream>

QuarkGame::QuarkGame()
{

}

void QuarkGame::init()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game::Init");
}

void QuarkGame::render()
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game::Render");
}

void QuarkGame::update(Input *input)
{
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game::Update");
}

QuarkGame::~QuarkGame()
{

}

