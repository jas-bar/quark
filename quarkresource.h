#ifndef QUARKRESOURCE_H
#define QUARKRESOURCE_H

#include <SDL.h>
#include <SDL_mixer.h>

class QuarkResource
{
public:
    QuarkResource();
    ~QuarkResource();
};

class QuarkImageResource : public QuarkResource {
private:
    SDL_Surface* surface;
public:
    QuarkImageResource(SDL_Surface* surface);
    SDL_Surface* getSurface();
    ~QuarkImageResource();

};

class QuarkSoundResource: public QuarkResource {
private:
    Mix_Chunk* chunk;
public:
    QuarkSoundResource(Mix_Chunk* chunk);
    Mix_Chunk* getChunk();
    ~QuarkSoundResource();
};

class QuarkMusicResource: public QuarkResource {
private:
    Mix_Music* music;
public:
    QuarkMusicResource(Mix_Music* music);
    Mix_Music* getMusic();
    ~QuarkMusicResource();
};

#endif // QUARKRESOURCE_H
