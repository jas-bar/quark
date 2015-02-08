#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "quarkresourceloader.h"

QuarkResource *QuarkIMGLoader::loadResource(const char *filePath)
{
    SDL_Surface* surface = IMG_Load(filePath);
    return new QuarkImageResource(surface);
}


QuarkResource *QuarkSoundLoader::loadResource(const char *filePath)
{
    Mix_Chunk* chunk = Mix_LoadWAV(filePath);
    return new QuarkSoundResource(chunk);
}


QuarkResource *QuarkMusicLoader::loadResource(const char *filePath)
{
    Mix_Music* music = Mix_LoadMUS(filePath);
    return new QuarkMusicResource(music);
}
