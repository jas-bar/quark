#include "input.h"
#include <SDL2/SDL.h>

Input::Input()
{
    quitRequested = false;
    mouse = new Mouse();
    registerListener(SDL_MOUSEBUTTONDOWN, mouse);
    registerListener(SDL_MOUSEBUTTONUP, mouse);
    registerListener(SDL_MOUSEMOTION, mouse);

    keyboard = new Keyboard();
    registerListener(SDL_KEYDOWN, keyboard);
    registerListener(SDL_KEYUP, keyboard);

    gameControllerManager = new GameControllerManager();
    gameControllerManager->init(this);
}

void Input::update()
{
    while(SDL_PollEvent(&event)){
        std::vector<InputListener*> listenerList = listeners[event.type];

        for(auto it = listenerList.begin(); it != listenerList.end(); ++it){
            InputListener* listener = (*it);
            listener->onEvent(&event);
        }
    }
}

void Input::registerListener(SDLEventType eventType, InputListener* listener)
{
    listeners[eventType].push_back(listener);
}

Keyboard* Input::getKeyboard()
{
    return keyboard;
}

Mouse* Input::getMouse()
{
    return mouse;
}

GameControllerManager* Input::getControllerManager()
{
    return gameControllerManager;
}

Input::~Input()
{
    /*for(auto mapIt = listeners.begin(); mapIt != listeners.end(); ++mapIt){
        std::pair<SDLEventType, std::vector<InputListener*>> pair = (*mapIt);
        for(int i = 0; i < pair.second.size(); ++i){
            InputListener* listener = pair.second[i];
            if(listener != (InputListener*)&mouse && listener != (InputListener*)&keyboard && listener != (InputListener*)&gameControllerManager)
                delete listener;
        }
    }*/
}



bool Keyboard::isKeyDown(SDL_Keycode key)
{
    return keyState[key];
}

void Keyboard::onEvent(SDL_Event* event)
{
    if(event->type == SDL_KEYDOWN){
        keyState[event->key.keysym.sym] = true;
    } else if(event->type == SDL_KEYUP){
        keyState[event->key.keysym.sym] = false;
    }
}


void Mouse::onEvent(SDL_Event* event)
{
    if(event->type == SDL_MOUSEMOTION){
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }

    if(event->type == SDL_MOUSEBUTTONDOWN)
        mouseState[event->button.button] = true;

    if(event->type == SDL_MOUSEBUTTONUP)
        mouseState[event->button.button] = false;
}

Sint32 Mouse::getMouseX()
{
    return mouseX;
}

Sint32 Mouse::getMouseY()
{
    return mouseY;
}


void GameControllerManager::addGameController(Input* input, SDL_JoystickID sdlJoystickIndex)
{
    controllers.push_back(GameController(sdlJoystickIndex));
}

void GameControllerManager::init(Input* input)
{
    int joyCount = SDL_NumJoysticks();
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Found %d joysticks", joyCount);
    for(int j = 0; j < joyCount; ++j){
        if(SDL_IsGameController(j)){
            addGameController(input, j);
        }
    }
}

int GameControllerManager::getControllerCount()
{
    return controllers.size();
}

GameController*GameControllerManager::getController(int num)
{
    return &(controllers.at(num));
}


GameController::GameController(int sdlIndex)
{
    this->sdlIndex = sdlIndex;
    this->controller = SDL_GameControllerOpen(sdlIndex);
}

void GameController::onEvent(SDL_Event* event)
{
    switch(event->type){
    case SDL_CONTROLLERAXISMOTION:
        if(event->caxis.which == sdlIndex){
            axes[event->caxis.axis] = event->caxis.value;
        }
        break;
    case SDL_CONTROLLERBUTTONDOWN:
        if(event->cbutton.which == sdlIndex){
            buttons[event->cbutton.button] = true;
        }
        break;
    case SDL_CONTROLLERBUTTONUP:
        if(event->cbutton.which == sdlIndex){
            buttons[event->cbutton.button] = false;
        }
        break;
    }
}


bool GameController::isButtonDown(Uint8 button)
{
    return buttons[button];
}

SDLJoyAxisValue GameController::getAxisValue(Uint8 axis)
{
    return axes[axis];
}

GameController::~GameController()
{
    SDL_GameControllerClose(controller);
}
