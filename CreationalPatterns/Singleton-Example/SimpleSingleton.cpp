#include "SimpleSingleton.h"

SimpleSingleton* SimpleSingleton::self = nullptr;

SimpleSingleton::SimpleSingleton() :
    someData(0)
{
    // ...
}

SimpleSingleton::~SimpleSingleton()
{
    // ...
}

SimpleSingleton* SimpleSingleton::instance()
{
    if (!self) {
        self = new SimpleSingleton();
    }

    return self;
}

void SimpleSingleton::recreation()
{
    if (self) {
        delete self;
    }
}

int SimpleSingleton::getSomeData()
{
    return someData;
}

void SimpleSingleton::setSomeData(const int data)
{
    if (data != someData) {
        someData = data;
    }
}
