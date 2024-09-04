#pragma once

#include <mutex>

class SafeSingleton
{
private:
    static SafeSingleton* self;
    static std::mutex mutex;

    SafeSingleton();
    ~SafeSingleton();

    SafeSingleton(const SafeSingleton&) = delete;
    SafeSingleton(SafeSingleton&&) = delete;
    SafeSingleton& operator=(const SafeSingleton&) = delete;
    SafeSingleton& operator=(SafeSingleton&&) = delete;

public:
    static SafeSingleton* instance();
    static void recreation();

    int getSomeData();
    void setSomeData(const int data);

private:
    int someData;

};
