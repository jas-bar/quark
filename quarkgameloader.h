#ifndef QUARKGAMELOADER_H
#define QUARKGAMELOADER_H

#include <memory>
#include <SDL.h>
#include <SDL_thread.h>
#include <SDL_log.h>
#include "quarkgame.h"
#include "quarkgamecontainer.h"

using namespace std;


class quarkgameloader
{
private:
    SDL_Thread* gameThread;

    unique_ptr<QuarkGameContainer> container;
    void preInit();
public:
    quarkgameloader();
    void loadGame(QuarkGame* g);
    ~quarkgameloader();
};

#endif // QUARKGAMELOADER_H
