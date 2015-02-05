#ifndef QUARKGAMESTATE_H
#define QUARKGAMESTATE_H

#include "input.h"

class QuarkGame;

class QuarkGameState
{
public:
    QuarkGameState();
    virtual void init() = 0;
    virtual void render() = 0;
    virtual void update(QuarkGame* game, Input* input) = 0;
    ~QuarkGameState();
};

#endif // QUARKGAMESTATE_H
