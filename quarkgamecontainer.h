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

typedef struct EngineSettings {
    char* windowTitle;
    int width, height, maxFPS;
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
