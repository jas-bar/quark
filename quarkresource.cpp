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
    textureID = 0;
}

SDL_Surface *QuarkImageResource::getSurface()
{
    return surface;
}

void QuarkImageResource::loadIntoGL()
{
    if(textureID != 0){
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0,
                     surface->format->BytesPerPixel,
                     surface->w, surface->h,
                     0, GL_BGR, GL_UNSIGNED_BYTE,
                     surface->pixels);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}

void QuarkImageResource::setGLParameter(GLenum param, GLuint value)
{
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, param, value);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint QuarkImageResource::getID()
{
    return textureID;
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
