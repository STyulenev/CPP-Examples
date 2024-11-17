#include "SomeClass.h"

#include <iostream>
#include <thread>
#include <atomic>

SomeClass::SomeClass()
{
    // ...
}

SomeClass::~SomeClass()
{
    // ...
}

// Пример порчи данных, когда два потока "наперегонки" работают с общим ресурсом.
void SomeClass::run()
{
    // Общие ресурсы
    int sharedCounter1 = 0;              // Общий ресурс, у которого будет race condition
    std::atomic<int> sharedCounter2 = 0; // Общий ресурс, у которого не будет race condition

    auto incrementCounter = [&sharedCounter1, &sharedCounter2]() -> void {
        for (int i = 0; i < 100000; i++) {
            // критическая часть
            sharedCounter1++;
            sharedCounter2++;
        }
    };

    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "sharedCounter1: " << sharedCounter1 << std::endl; // Результат не будет равен 200000
    std::cout << "sharedCounter2: " << sharedCounter2 << std::endl; // Результат будет равен 200000
}
