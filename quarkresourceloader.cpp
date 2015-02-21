#include <string>
#include <fstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "quarkresourceloader.h"

using namespace std;

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

bool QuarkShaderProgramLoader::fileExists(std::string filePath)
{
    return false;
}

std::string QuarkShaderProgramLoader::readFile(std::string filePath)
{
    std::string result("");
    std::ifstream file(filePath);
    std::string line;
    if(file.is_open()){
        SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Loading shader from %s", filePath.c_str());
        while(std::getline(file, line)){
            result += line + "\n";
        }
        file.close();
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to load shader from %s", filePath.c_str());
    }
    return result;
}

QuarkResource* QuarkShaderProgramLoader::loadResource(const char* filePath)
{
    std::string absoluteFilePath = filePath;
    int extLength = absoluteFilePath.length() - absoluteFilePath.find_last_of('.') - 1;
    std::string ext = absoluteFilePath.substr(absoluteFilePath.find_last_of('.')+1, extLength);

    std::string fragShaderName = absoluteFilePath.replace(absoluteFilePath.find(ext), ext.length(), ".frag");
    std::string vertShaderName = absoluteFilePath.replace(absoluteFilePath.find(ext), ext.length(), ".vert");

    std::string fragShaderString("");
    std::string vertShaderString("");

    if(fileExists(fragShaderName)){
        fragShaderString = readFile(fragShaderName);
    }

    if(fileExists(vertShaderName)){
        vertShaderString = readFile(vertShaderName);
    }

    return new QuarkShaderProgramResource(fragShaderString, vertShaderString);
}


QuarkResource*QuarkJoyMappingsLoader::loadResource(const char* filePath)
{
    return new QuarkJoyMappingsResource(filePath);
}
