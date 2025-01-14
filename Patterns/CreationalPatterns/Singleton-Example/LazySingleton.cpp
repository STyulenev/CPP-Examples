#include "LazySingleton.h"

#include <iostream>

LazySingleton::LazySingleton() :
    m_someData(0)
{
    std::cout << "LazySingleton::LazySingleton()" << std::endl;
}

LazySingleton::~LazySingleton()
{
    std::cout << "LazySingleton::~LazySingleton()" << std::endl;
}

LazySingleton& LazySingleton::instance()
{
    static LazySingleton instance;
    return instance;
}

int LazySingleton::getSomeData()
{
    return m_someData;
}

void LazySingleton::setSomeData(const int data)
{
    if (data != m_someData) {
        m_someData = data;
    }
}
