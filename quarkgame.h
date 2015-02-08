#ifndef QUARKGAME_H
#define QUARKGAME_H

#include <map>
#include <SDL.h>
#include "input.h"

class QuarkGameState;

class QuarkGame
{
private:
    std::map<int, QuarkGameState*> gameStates;
    QuarkGameState* currentState;
protected:
    void addState(QuarkGameState* state, int stateId);
public:
    QuarkGame();
    virtual void init(SDL_Window* window);
    virtual void initStates() = 0;
    virtual void render();
    virtual void update(Input* input);
    void switchState(int newState);
    ~QuarkGame();
};

#endif // QUARKGAME_H
