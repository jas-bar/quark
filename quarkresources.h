#ifndef QUARKRESOURCES_H
#define QUARKRESOURCES_H

#include <map>
#include <memory>
#include <string>
#include "quarkresource.h"
#include "quarkresourceloader.h"

class QuarkResourceManager
{
private:
    std::map<std::string, std::unique_ptr<QuarkResource>> resourceMap;
    std::map<std::string, std::unique_ptr<QuarkResourceLoader>> loaders;

    std::string getKey(std::string relativeFilePath);
    QuarkResource* loadResource(std::string filePath);

public:
    QuarkResourceManager();

    int loadResources(const char* resourcesPath);
    QuarkResource* getResource(const char* key);


    ~QuarkResourceManager();
};

#endif // QUARKRESOURCES_H
