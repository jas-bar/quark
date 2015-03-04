Getting started with Quark                         {#getting_started}
============

# Installation
Before installing quark, you need to grab some dependencies.

## Dependencies
* C++ compiler with C++2011 support
* make, cmake(>=2.8)
* libgl or libgles
* SDL2
* SDL2_mixer
* SDL2_image


After grabbing the dependencies, you can build & install quark.

## Unix
On Unix, this can be done by a few commands:
	
	cd quark
	mkdir build && cd build
	cmake ..
	sudo make install

## Windows
I'm not sure about compatibility with windows, but if you managed to setup
MinGW or Cygwin environment, you should be able to build quark like on unix.

# Quark as a library

After installation, Quark should be registered as a pkg-config module.
That means, you can use it with any build system that supports pkg-config.

## CMake
If you're using CMake, you need to add following lines to your CMakeLists.txt

	include(FindPkgConfig)
	pkg_search_module(QUARK REQUIRED quark)

This will find the quark library. Then, you need to add include directories and library files.

	include_directories(${QUARK_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${QUARK_LIBRARIES})

# Coding your game!

Watch out, this section is WIP!

## Quark Game skeleton

Before we actually get into coding, it's very important that I explain you how the game code is supposed to look in quark.

The most important part of your game will be the Game class. This will be a child class of QuarkGame.
Each game has three methods: init, render, update.

In init, game loads resources and sets up the initial state.

In render, game draws the game world on screen.

In update, game updates logic and reads user input.

In Quark, game is split up into several game states. A Game State may be Main Menu screen, in game state or paused game.
Each game state has its own init,render,update methods, so the game code is split up even more. 
Game can obviously switch between these states. 

## main.cpp

This is what needs to be done in main.cpp:
* Create the game instance
* Define settings for the engine
* Start the game

And this is how you achieve it:

	#include <SDL.h>
	#include <quark/quark.h>
	#include "quarktestgame.h"
	#include <iostream>
	
	using namespace std;
	
	int main(int argc, char *argv[]){
		// create quark game loader, which will take care of your game
		QuarkGameLoader loader;
		
		// create game instance
		QuarkTestGame game;
		
		// define engine settings
		EngineSettings settings;
		settings.flags = SDL_WINDOW_OPENGL;
		settings.width = 800;
		settings.height = 600;
		settings.maxFPS = 60;
		settings.windowTitle = "Quark Engine Test";
		
		// start the game
		loader.loadGame(&game, &settings);
		return 0;
	}
