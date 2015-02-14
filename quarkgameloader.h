#ifndef QUARKGAMELOADER_H
#define QUARKGAMELOADER_H

#include <memory>
#include <SDL_thread.h>

#include "quarkgame.h"
#include "quarkgamecontainer.h"

using namespace std;


class QuarkGameLoader
{
private:
    SDL_Thread* gameThread;

    void preInit();
public:
    QuarkGameLoader();
    void loadGame(QuarkGame* g);
    ~QuarkGameLoader();
};

#endif // QUARKGAMELOADER_H
