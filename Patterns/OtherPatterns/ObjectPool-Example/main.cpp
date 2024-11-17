#include <iostream>

#include "ObjectPool.h"

int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
    Resource* one;
    Resource* two;

    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    pool->returnResource(one);
    pool->returnResource(two);

    one = pool->getResource();
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
    two = pool->getResource();
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    return 0;
}
