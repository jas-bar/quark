#include <SDL.h>
#include <iostream>
#include "quarkgame.h"
#include "quarkgameloader.h"

using namespace std;

int main(){

    QuarkGameLoader loader;
    QuarkGame game;
    loader.loadGame(&game);




/*
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    string imagePath = "hello.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    while(true){
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);

        SDL_Delay(16);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();*/
}

