#pragma once

#include <list>

#include "Resource.h"

class ObjectPool
{
private:
    std::list<Resource*> resources;

    static ObjectPool* instance;

    ObjectPool();
    ~ObjectPool();
    // ...

public:
    static ObjectPool* getInstance();

    Resource* getResource();
    void returnResource(Resource* object);

};
