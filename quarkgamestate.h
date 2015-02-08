#ifndef QUARKGAMESTATE_H
#define QUARKGAMESTATE_H

#include "quarkgame.h"
#include "input.h"


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
