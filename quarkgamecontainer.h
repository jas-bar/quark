#ifndef QUARKGAMECONTAINER_H
#define QUARKGAMECONTAINER_H

#include <memory>
#include <SDL2/SDL.h>
#include "quarkgame.h"
#include "input.h"

class QuarkGCQuitListener : public InputListener {
private:
    bool quitRequested;
public:
    QuarkGCQuitListener();
    void onEvent(SDL_Event* event);
    bool isQuitRequested();
};

/** @brief Stores settings of the engine
  */
typedef struct EngineSettings {
    /**
     * @brief Title of game's window
     */
    char* windowTitle;

    /**
     * @brief Width of game's window
     */
    int width;

    /**
     * @brief Height of game's window
     */
    int height;

    /**
     * @brief Maximum FPS to allow the game to run on
     */
    int maxFPS;

    /**
     * @brief SDL_WindowFlags for the window.
     * Default = SDL_WINDOW_OPENGL
     */
    SDL_WindowFlags flags;
}EngineSettings;

class QuarkGameContainer
{
private:
    std::unique_ptr<Input> input;
    QuarkGame* game;
    SDL_Window* window;
    SDL_GLContext glContext;
    Uint32 tickStartTime;
    Uint32 maxFPS, idealFrameDuration;
    bool running;
    QuarkGCQuitListener quitListener;
public:
    QuarkGameContainer();
    void setGame(QuarkGame* g);
    void init(EngineSettings* settings);
    void render();
    void update();
    bool isRunning();
    void tickStart();
    void tickEnd();
    ~QuarkGameContainer();
};

#endif // QUARKGAMECONTAINER_H
