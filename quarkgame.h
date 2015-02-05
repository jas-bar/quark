#ifndef QUARKGAME_H
#define QUARKGAME_H

#include "input.h"

class QuarkGame
{
public:
    QuarkGame();
    void init();
    void render();
    void update(Input* input);
    ~QuarkGame();
};

#endif // QUARKGAME_H
