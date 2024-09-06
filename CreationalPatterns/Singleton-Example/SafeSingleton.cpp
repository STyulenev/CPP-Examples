#include "SafeSingleton.h"

SafeSingleton* SafeSingleton::self = nullptr;
std::mutex SafeSingleton::mutex;

SafeSingleton::SafeSingleton() :
    someData(0)
{
    // ...
}

SafeSingleton::~SafeSingleton()
{
    // ...
}

SafeSingleton* SafeSingleton::instance()
{
    std::lock_guard<std::mutex> lock(mutex);

    if (!self) {
        self = new SafeSingleton();
    }

    return self;
}

void SafeSingleton::recreation()
{
    std::lock_guard<std::mutex> lock(mutex);

    if (self) {
        delete self;
    }
}

int SafeSingleton::getSomeData()
{
    std::lock_guard<std::mutex> lock(mutex);

    return someData;
}

void SafeSingleton::setSomeData(const int data)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (data != someData) {
        someData = data;
    }
}
