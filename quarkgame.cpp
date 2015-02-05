#include "quarkgame.h"

#include <iostream>

void QuarkGame::addState(QuarkGameState *state, int stateId)
{
    if(gameStates[stateId] == NULL){
        gameStates[stateId] = state;
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Game state with id %d already exists!!!", stateId);
    }
}

QuarkGame::QuarkGame()
{
    currentState = NULL;
}

void QuarkGame::init()
{
    initStates();
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

QuarkGame::~QuarkGame()
{

}

