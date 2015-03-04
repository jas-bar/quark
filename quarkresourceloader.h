#ifndef QUARKRESOURCELOADER_H
#define QUARKRESOURCELOADER_H

#include <string>
#include "quarkresource.h"

/**
 * @brief Loads resources from files
 */
class QuarkResourceLoader
{
public:
    /**
     * @brief Returns QuarkResource loaded from the given file
     * @param filePath File to load resource from
     * @return The resource loaded from the given file
     */
    virtual QuarkResource* loadResource(const char* filePath) = 0;
};

// Here are various loaders. You can check quark implementation if you want to see how these work...

class QuarkIMGLoader : public QuarkResourceLoader {
public:
    QuarkResource* loadResource(const char *filePath);
};

class QuarkSoundLoader : public QuarkResourceLoader {
public:
    QuarkResource* loadResource(const char *filePath);
};

class QuarkMusicLoader : public QuarkResourceLoader {
public:
    QuarkResource* loadResource(const char *filePath);
};

class QuarkShaderProgramLoader : public QuarkResourceLoader {
private:
    bool fileExists(std::string filePath);
    std::string readFile(std::string filePath);

public:
    QuarkResource* loadResource(const char *filePath);
};

class QuarkJoyMappingsLoader : public QuarkResourceLoader {
public:
    QuarkResource* loadResource(const char *filePath);
};

#endif // QUARKRESOURCELOADER_H
