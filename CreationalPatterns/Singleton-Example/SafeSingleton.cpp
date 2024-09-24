#include "SafeSingleton.h"

#include <iostream>

SafeSingleton* SafeSingleton::self = nullptr;
std::mutex SafeSingleton::mutex;

SafeSingleton::SafeSingleton() :
    m_someData(0)
{
    std::cout << "SafeSingleton::SafeSingleton()" << std::endl;
}

SafeSingleton::~SafeSingleton()
{
    std::cout << "SafeSingleton::~SafeSingleton()" << std::endl;
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

    return m_someData;
}

void SafeSingleton::setSomeData(const int data)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (data != m_someData) {
        m_someData = data;
    }
}
