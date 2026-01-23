#pragma once

#include <atomic>
#include <mutex>

// Старая реализация
class Singleton
{
private:
    static std::atomic<Singleton*> instance;
    static std::mutex mtx;

    Singleton();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance();

    void doSomething();

    ~Singleton();

};

// Современная реализация на C++11
class ModernSingleton
{
private:
    ModernSingleton();

public:
    static ModernSingleton& getInstance();

    void doSomething();

};
