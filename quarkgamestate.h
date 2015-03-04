#ifndef QUARKGAMESTATE_H
#define QUARKGAMESTATE_H

#include "quarkgame.h"
#include "input.h"

/**
 * @brief Represents one state of your game.
 * This may be used for different GUIs of the game.
 * You could have for example a MainMenuState and an InGameState
 */
class QuarkGameState
{
public:
    QuarkGameState();

    /**
     * @brief Initializes this game state
     * @param game The game this state belongs to
     */
    virtual void init(QuarkGame* game) = 0;

    /**
     * @brief Renders what should be displayed on the screen
     */
    virtual void render() = 0;

    /**
     * @brief Updates this state's logic
     * @param game The game this state belongs to
     * @param input Input interface
     */
    virtual void update(QuarkGame* game, Input* input) = 0;

    ~QuarkGameState();
};

#endif // QUARKGAMESTATE_H
