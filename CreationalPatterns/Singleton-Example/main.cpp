#include <iostream>
#include <thread>

#include "SimpleSingleton.h"
#include "SafeSingleton.h"

void testSimpleSingleton();
void testSafeSingleton();

int main()
{
    testSimpleSingleton();
    testSafeSingleton();

    return 0;
}

void testSimpleSingleton()
{
    std::cout << "testSimpleSingleton()" << std::endl;

    std::cout << SimpleSingleton::instance()->getSomeData() << std::endl;
    SimpleSingleton::instance()->setSomeData(5);
    std::cout << SimpleSingleton::instance()->getSomeData() << std::endl;
}

void testSafeSingleton()
{
    std::cout << "testSafeSingleton()" << std::endl;

    std::thread thread1([]() -> void {
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
        SafeSingleton::instance()->setSomeData(5);
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
    });
    std::thread thread2([]() -> void {
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
        SafeSingleton::instance()->setSomeData(4);
        std::cout << SafeSingleton::instance()->getSomeData() << std::endl;
    });

    thread1.join();
    thread2.join();
}
