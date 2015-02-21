#ifndef QUARKRESOURCE_H
#define QUARKRESOURCE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>

class QuarkResource
{
public:
    QuarkResource();
    ~QuarkResource();
};

class QuarkImageResource : public QuarkResource {
private:
    SDL_Surface* surface;
    GLuint textureID;
public:
    QuarkImageResource(SDL_Surface* surface);
    SDL_Surface* getSurface();
    void loadIntoGL();
    void setGLParameter(GLenum param, GLuint value);
    GLuint getID();
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

class QuarkShaderProgramResource : public QuarkResource {
private:
    std::string fragShaderText, vertShaderText;
    GLuint programID;

    GLuint loadShader(GLenum shaderType, std::string shaderText);
public:
    QuarkShaderProgramResource(std::string fragText, std::string vertText);
    GLuint link();
    GLuint getProgramID();
    ~QuarkShaderProgramResource();
};

class QuarkJoyMappingsResource : public QuarkResource {
private:
    const char* filePath;
public:
    QuarkJoyMappingsResource(const char* filePath);
    int load();
};

#endif // QUARKRESOURCE_H
