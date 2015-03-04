#ifndef QUARKGAMELOADER_H
#define QUARKGAMELOADER_H

#include <memory>
#include <SDL2/SDL_thread.h>

#include "quarkgame.h"
#include "quarkgamecontainer.h"

using namespace std;

/**
 * @brief Loads your game :)
 * ...and keeps your main.cpp clear.
 */
class QuarkGameLoader
{
private:
    SDL_Thread* gameThread;

    void preInit();
public:
    QuarkGameLoader();

    /**
     * @brief Starts the specified game
     * @param g The game to start(you must create the game yourself and pass it here)
     * @param settings EngineSettings to use
     */
    void loadGame(QuarkGame* g, EngineSettings* settings);

    ~QuarkGameLoader();
};

#endif // QUARKGAMELOADER_H
