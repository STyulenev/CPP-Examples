#include "SomeClass.h"

#include <iostream>
#include <thread>
#include <mutex>

SomeClass::SomeClass()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SomeClass::~SomeClass()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void SomeClass::run1()
{
    std::cout << "Example: "<< __FUNCTION__ << std::endl;

    std::mutex mutex1;
    std::mutex mutex2;

    std::thread thread1([&mutex1, &mutex2] {
        std::cout << "Thread 1. Begining." << std::endl;

        mutex1.lock(); // Блокировка первым потоком первого мьютекса
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mutex2.lock(); // Блокировка первым потоком второго мьютекса. Deadlock.

        std::cout << "Thread 1. Ending." << std::endl; // Недостижимая точка для Thread 1
    });

    std::thread thread2([&mutex1, &mutex2] {
        std::cout << "Thread 2. Begining." << std::endl;

        mutex2.lock(); // Блокировка вторым потоком второго мьютекса
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mutex1.lock(); // Блокировка вторым потоком первого мьютекса. Deadlock.

        std::cout << "Thread 2. Ending." << std::endl; // Недостижимая точка для Thread 2
    });

    thread1.join();
    thread2.join();
}

void SomeClass::run2()
{
    std::cout << "Example: "<< __FUNCTION__ << std::endl;

    std::mutex mutex;
    std::mutex mutex2;

    std::thread thread([&mutex, &mutex2] {
        std::cout << "Thread. Begining." << std::endl;

        mutex.lock(); // Блокировка мьютекса

        // ...
        // mutex.try_lock(); - пропустили для примера

        mutex.lock(); // Повторная блокировка уже заблокированного мьютекса. Deadlock.

        std::cout << "Thread. Ending." << std::endl; // Недостижимая точка
    });

    thread.join();
}
