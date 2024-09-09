#include "ObjectPool.h"

#include <iostream>

ObjectPool* ObjectPool::instance = nullptr;

ObjectPool::ObjectPool()
{
    // ...
}

ObjectPool::~ObjectPool()
{
    // ...
}

ObjectPool* ObjectPool::getInstance()
{
    if (instance == 0) {
        instance = new ObjectPool();
    }

    return instance;
}

Resource* ObjectPool::getResource()
{
    if (resources.empty()) {
        std::cout << "Creating new resource in ObjectPool" << std::endl;

        return new Resource();
    } else {
        std::cout << "Pop resource from ObjectPool" << std::endl;

        Resource* resource = resources.front();
        resources.pop_front();
        return resource;
    }
}

void ObjectPool::returnResource(Resource* object)
{
    object->reset();
    resources.push_back(object);
}
