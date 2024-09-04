#pragma once

class SimpleSingleton
{
private:
    static SimpleSingleton* self;

    SimpleSingleton();
    ~SimpleSingleton();

    SimpleSingleton(const SimpleSingleton&) = delete;
    SimpleSingleton(SimpleSingleton&&) = delete;
    SimpleSingleton& operator=(const SimpleSingleton&) = delete;
    SimpleSingleton& operator=(SimpleSingleton&&) = delete;

public:
    static SimpleSingleton* instance();
    static void recreation();

    int getSomeData();
    void setSomeData(const int data);

private:
    int someData;

};
