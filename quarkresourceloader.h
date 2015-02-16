#ifndef QUARKRESOURCELOADER_H
#define QUARKRESOURCELOADER_H

#include <string>
#include "quarkresource.h"


class QuarkResourceLoader
{
public:
    virtual QuarkResource* loadResource(const char* filePath) = 0;
};

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

#endif // QUARKRESOURCELOADER_H
