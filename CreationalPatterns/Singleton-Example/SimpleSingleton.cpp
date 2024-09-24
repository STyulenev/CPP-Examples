#include "SimpleSingleton.h"

#include <iostream>

SimpleSingleton* SimpleSingleton::self = nullptr;

SimpleSingleton::SimpleSingleton() :
    m_someData(0)
{
    std::cout << "SimpleSingleton::SimpleSingleton()" << std::endl;
}

SimpleSingleton::~SimpleSingleton()
{
    std::cout << "SimpleSingleton::~SimpleSingleton()" << std::endl;
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
    return m_someData;
}

void SimpleSingleton::setSomeData(const int data)
{
    if (data != m_someData) {
        m_someData = data;
    }
}
