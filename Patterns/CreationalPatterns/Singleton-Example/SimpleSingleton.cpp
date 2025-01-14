#include "SimpleSingleton.h"

#include <iostream>

#if IS_POINTER
    SimpleSingleton* SimpleSingleton::self = nullptr;
#else
    SimpleSingleton SimpleSingleton::self;
#endif

SimpleSingleton::SimpleSingleton() :
    m_someData(0)
{
    std::cout << "SimpleSingleton::SimpleSingleton()" << std::endl;
}

SimpleSingleton::~SimpleSingleton()
{
    std::cout << "SimpleSingleton::~SimpleSingleton()" << std::endl;
}

#if IS_POINTER
SimpleSingleton* SimpleSingleton::instance()
{
    if (!self) {
        self = new SimpleSingleton();
    }

    return self;
}
#else
SimpleSingleton& SimpleSingleton::instance()
{
    return self;
}
#endif

#if IS_POINTER
void SimpleSingleton::recreation()
{
    if (self) {
        delete self;
    }
}
#endif

int SimpleSingleton::getSomeData()
{
    return m_someData;
}

void SimpleSingleton::setSomeData(const int data)
{
    if (data != m_someData) {
        m_someData = data;
    }
}
