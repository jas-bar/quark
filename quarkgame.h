#ifndef QUARKGAME_H
#define QUARKGAME_H

#include <map>
#include <SDL2/SDL.h>
#include "input.h"

class QuarkGameState;

/**
 * @brief Game skeleton
 */
class QuarkGame
{
private:
    std::map<int, QuarkGameState*> gameStates;
    QuarkGameState* currentState;
protected:
    /**
     * @brief Adds another game state to this game
     * @param state The QuarkGameState to add
     * @param stateId ID of the state - <b>HAS TO BE UNIQUE!</b>
     */
    void addState(QuarkGameState* state, int stateId);

public:
    QuarkGame();

    /**
     * @brief Initializes your game. Add and initialize your game states here!
     * @param window SDL window in case you need to customize it somehow(flags are set using QuarkGameLoader)
     * @param input Input interface to register listeners
     */
    virtual void init(SDL_Window* window, Input* input);

    /**
     * @brief Draws your game's content to the screen
     * Only SDL_GL_SwapWindow is done automatically after this.
     * No GL instructions are executed before this, so you need to do glClearColor and stuff manually
     * <B>Only override if you don't want to use states</B> - states are handled by the default implementation of game
     * this calls `currentState->render();`
     */
    virtual void render();

    /**
     * @brief Updates your game's logic
     * @param input The Input interface
     * <B>Only override if you don't want to use states</B> - states are handled by the default implementation of game
     * this calls `currentState->update();`
     */
    virtual void update(Input* input);

    /**
     * @brief Changes your game's state
     * @param newState ID of the new state where you want to switch
     */
    void switchState(int newState);

    ~QuarkGame();
};

#endif // QUARKGAME_H
