#ifndef QUARKRESOURCE_H
#define QUARKRESOURCE_H

#include <string>
#include <SDL2/SDL.h>
#include <GLES2/gl2.h>
#include <SDL2/SDL_mixer.h>

/**
 * @brief Represents a generic resource. It might be image, sound, shader, whatever...
 */
class QuarkResource
{
public:
    QuarkResource();
    ~QuarkResource();
};

/**
 * @brief Represents an image resource. Holds pointer to SDL_Surface.
 */
class QuarkImageResource : public QuarkResource {
private:
    SDL_Surface* surface;
    GLuint textureID;
public:
    QuarkImageResource(SDL_Surface* surface);

    /**
     * @brief
     * @return The SDL_Surface created from the image
     */
    SDL_Surface* getSurface();

    /**
     * @brief Loads this image into OpenGL and assigns it an ID
     */
    void loadIntoGL();

    /**
     * @brief Sets an OpenGL parameter for this texture
     * @param param The OpenGL parameter to set
     * @param value Value to set the parameter to
     * This only calls `glTexParameteri(GL_TEXTURE_2D, param, value);` for this texture...
     */
    void setGLParameter(GLenum param, GLuint value);

    /**
     * @brief Obtains ID of this texture for use with OpenGL
     * @return ID of this texture in OpenGL system.
     * <b>Beware: this only works correctly after `loadIntoGL` was called</b>
     */
    GLuint getID();

    ~QuarkImageResource();

};

/**
 * @brief Represents a sound effect. Holds pointer to Mix_Chunk
 */
class QuarkSoundResource: public QuarkResource {
private:
    Mix_Chunk* chunk;
public:
    QuarkSoundResource(Mix_Chunk* chunk);

    /**
     * @brief Returns pointer to Mix_Chunk
     * @return Pointer to Mix_Chunk
     */
    Mix_Chunk* getChunk();

    ~QuarkSoundResource();
};

/**
 * @brief Represents a music which may be played in loops. Holds pointer to Mix_Music.
 */
class QuarkMusicResource: public QuarkResource {
private:
    Mix_Music* music;
public:
    QuarkMusicResource(Mix_Music* music);

    /**
     * @brief Returns pointer to Mix_Music
     * @return Pointer to Mix_Music
     */
    Mix_Music* getMusic();

    ~QuarkMusicResource();
};

/**
 * @brief Shader program resource. It consists of fragment shader and vertex shader.
 */
class QuarkShaderProgramResource : public QuarkResource {
private:
    std::string fragShaderText, vertShaderText;
    GLuint programID;

    GLuint loadShader(GLenum shaderType, std::string shaderText);
public:
    QuarkShaderProgramResource(std::string fragText, std::string vertText);

    /**
     * @brief Attaches shaders together into one program
     * @return Result of glGetProgramiv(GL_LINK_STATUS)
     */
    GLuint link();

    /**
     * @brief Obtains ID of this program
     * @return ID of this program to use with OpenGL.
     * <b>Beware: this only works correctly after `link` was called</b>
     */
    GLuint getProgramID();

    ~QuarkShaderProgramResource();
};

/**
 * @brief Joystick mappings in the resource system
 */
class QuarkJoyMappingsResource : public QuarkResource {
private:
    const char* filePath;
public:
    QuarkJoyMappingsResource(const char* filePath);

    /**
     * @brief Loads the mappings into SDL
     * @return Number of mappings added, -1 on error
     */
    int load();
};

#endif // QUARKRESOURCE_H
