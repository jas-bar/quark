#ifndef QUARKRESOURCES_H
#define QUARKRESOURCES_H

#include <map>
#include <memory>
#include <string>


class QuarkResources
{
private:
    std::map<std::string,std::unique_ptr<QuarkResource>> resourceMap;

public:
    QuarkResources();

    int loadResources(std::string resourcesPath);


    ~QuarkResources();
};

#endif // QUARKRESOURCES_H
