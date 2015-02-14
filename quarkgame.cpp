#include "quarkgame.h"

#include <iostream>
#include "quarkgamestate.h"

void QuarkGame::addState(QuarkGameState *state, int stateId)
{
    if(gameStates[stateId] == NULL){
        state->init(this);
        gameStates[stateId] = state;
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Game state with id %d already exists!!!", stateId);
    }
}

QuarkGame::QuarkGame()
{
    currentState = NULL;
    std::cout << "QuarkGame::QuarkGame" << std::endl;
}

void QuarkGame::init(SDL_Window* window)
{
}

void QuarkGame::render()
{
    currentState->render();
}

void QuarkGame::update(Input *input)
{
    currentState->update(this, input);
}

void QuarkGame::switchState(int newState)
{
    currentState = gameStates[newState];
}

void QuarkGame::print()
{
    std::cout << "QuarkGame::Print" << std::endl;
}

QuarkGame::~QuarkGame()
{

}

