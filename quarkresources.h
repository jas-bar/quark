#ifndef QUARKRESOURCES_H
#define QUARKRESOURCES_H

#include <map>
#include <memory>
#include <string>
#include "quarkresource.h"
#include "quarkresourceloader.h"

/**
 * @brief Loads images, sounds, shaders, and joystick mappings
 *
 */
class QuarkResourceManager
{
private:
    std::map<std::string, std::unique_ptr<QuarkResource>> resourceMap;
    std::map<std::string, QuarkResourceLoader*> loaders;

    std::string getKey(std::string relativeFilePath);
    QuarkResource* loadResource(std::string filePath);

    std::unique_ptr<QuarkResourceLoader> imgLoader, soundLoader, musLoader, mappingLoader;

public:
    QuarkResourceManager();

    /**
     * @brief Loads resources from specified folder
     * @param resourcesPath Path to the folder
     * @return Always 0, will be used for errors in the future
     */
    int loadResources(const char* resourcesPath);

    /**
     * @brief Returns resource based on given key.
     * @param key If you want `res/example/something.png`, your key is `example.something`. You don't need to care about the file extension.
     * @return The resource you wanted. You then need to cast it accordingly to get the correct data...
     */
    QuarkResource* getResource(const char* key);


    ~QuarkResourceManager();
};

#endif // QUARKRESOURCES_H
