#include "Singletons.h"

#include <iostream>
#include <thread>

std::atomic<Singleton*> Singleton::instance = nullptr;
std::mutex Singleton::mtx;

Singleton::Singleton()
{
    std::cout << "Singleton was created in thread  " << std::this_thread::get_id() << std::endl;
}

Singleton* Singleton::getInstance()
{
    Singleton* tmp = instance.load(std::memory_order_acquire);

    if (tmp == nullptr) {  // Первая проверка (без блокировки)
        std::lock_guard<std::mutex> lock(mtx);
        tmp = instance.load(std::memory_order_relaxed);

        if (tmp == nullptr) {  // Вторая проверка (с блокировкой)
            tmp = new Singleton();
            instance.store(tmp, std::memory_order_release);
        }
    }

    return tmp;
}

void Singleton::doSomething()
{
    std::cout << "Singleton is using in thread " << std::this_thread::get_id() << std::endl;
}

Singleton::~Singleton()
{
    std::cout << "Singleton was destroyed" << std::endl;
}

ModernSingleton::ModernSingleton()
{
    std::cout << "ModernSingleton was created" << std::endl;
}

ModernSingleton &ModernSingleton::getInstance()
{
    static ModernSingleton instance;  // Потокобезопасно начиная с C++11
    return instance;
}

void ModernSingleton::doSomething()
{
    std::cout << "ModernSingleton is using" << std::endl;
}
