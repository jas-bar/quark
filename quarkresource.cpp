#include "quarkresource.h"
#include <SDL_mixer.h>

QuarkResource::QuarkResource()
{

}

QuarkResource::~QuarkResource()
{

}



QuarkImageResource::QuarkImageResource(SDL_Surface *surface)
{
    this->surface = surface;
}

SDL_Surface *QuarkImageResource::getSurface()
{
    return surface;
}

QuarkImageResource::~QuarkImageResource()
{
    SDL_FreeSurface(surface);
}


QuarkSoundResource::QuarkSoundResource(Mix_Chunk *chunk)
{
    this->chunk = chunk;
}

Mix_Chunk *QuarkSoundResource::getChunk()
{
    return chunk;
}

QuarkSoundResource::~QuarkSoundResource()
{
    Mix_FreeChunk(chunk);
}


QuarkMusicResource::QuarkMusicResource(Mix_Music *music)
{
    this->music = music;
}

Mix_Music *QuarkMusicResource::getMusic()
{
    return music;
}

QuarkMusicResource::~QuarkMusicResource()
{
    Mix_FreeMusic(music);
}
