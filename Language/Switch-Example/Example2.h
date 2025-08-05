#pragma once

#include <iostream>

/*
 * Разные варианции оператора switch
 */
namespace Example2
{

// Диапазонный switch
void test1()
{
    int control = 15;

    switch (control) {
    case 0 ... 10:
        std::cout << "0 ... 10" << std::endl;
        break;
    case 11 ... 20:
        std::cout << "11 ... 20" << std::endl;
        break;
    case 21 ... 30:
        std::cout << "21 ... 30" << std::endl;
        break;
    default:
        std::cout << "default" << std::endl;
        break;
    }
}

// switch для bool
void test2()
{
    bool control = false;

    switch (control) {
    case true:
        std::cout << "true" << std::endl;
        break;
    case false:
        std::cout << "false" << std::endl;
    }
}

// switch с переменной
void test3()
{
    auto getData = []() -> int {
        // ...

        return 3;
    };
    switch(int value = getData(); value) {
    case 1:
        std::cout << "1" << std::endl;
        break;
    case 2:
        std::cout << "2" << std::endl;
        break;
    case 3:
        std::cout << "3" << std::endl;
        break;
    default:
        std::cout << "default" << std::endl;
        break;
    }
}

// switch с enum и оператором \

enum Flags
{
    good = 0,
    fail = 1,
    bad  = 2,
    eof  = 4
};

constexpr Flags operator|(Flags f1, Flags f2)
{
    return Flags(int(f1) | int(f2));
}

void test4()
{
    Flags flag = Flags::bad | Flags::eof;

    switch (flag) {
    case Flags::good:
        std::cout << "good" << std::endl;
        break;
    case Flags::bad:
        std::cout << "bad" << std::endl;
        break;
    case Flags::eof:
        std::cout << "eof" << std::endl;
        break;
    case Flags::bad | Flags::eof:
        std::cout << "bad | eof" << std::endl;
        break;
    default:
        std::cout << "default" << std::endl;
        break;
    }
}

} // namespace Example2
