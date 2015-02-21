#include "quarkresource.h"
#include <SDL_mixer.h>
#include <SDL_opengles2.h>

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


GLuint QuarkShaderProgramResource::loadShader(GLenum shaderType, std::string shaderText)
{
    const char* shaderCSTR = shaderText.c_str();
    const GLint strLen = (GLint)shaderText.length() + 1;

    GLuint shaderObject = glCreateShader(shaderType);
    glShaderSource(shaderObject, 1, &shaderCSTR, &strLen);
    glCompileShader(shaderObject);
    glAttachShader(programID, shaderObject);

    return shaderObject;
}

QuarkShaderProgramResource::QuarkShaderProgramResource(std::string fragText, std::string vertText)
{
    this->fragShaderText = fragText;
    this->vertShaderText = vertText;
    programID = 0;
}

GLuint QuarkShaderProgramResource::link()
{
    if(vertShaderText.length() == 0 && fragShaderText.length() == 0){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Linking shader failed: none of the needed files are present");
        return 0;
    }
    GLuint vertexShaderObject, fragmentShaderObject;
    GLint linked;

    programID = glCreateProgram();

    if(vertShaderText.length() > 0){
        vertexShaderObject = loadShader(GL_VERTEX_SHADER, vertShaderText);
    }

    if(fragShaderText.length() > 0){
        fragmentShaderObject = loadShader(GL_FRAGMENT_SHADER, fragShaderText);
    }

    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &linked);

    return linked;
}

GLuint QuarkShaderProgramResource::getProgramID()
{
    return programID;
}

QuarkShaderProgramResource::~QuarkShaderProgramResource()
{

}


QuarkJoyMappingsResource::QuarkJoyMappingsResource(const char* filePath)
{
    this->filePath = filePath;
}

int QuarkJoyMappingsResource::load()
{
    return SDL_GameControllerAddMappingsFromFile(filePath);
}
