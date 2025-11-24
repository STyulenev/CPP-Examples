#pragma once

#include <iostream>

/*
 * if и if/else
 */

namespace Example1 {

// Последовательность проверки условий (Пример с bool переменными)
void test1()
{
    const bool a = true;
    const bool b = false;
    const bool c = true;
    const bool d = false;

    if (a && b) // Не сработает
    {
        std::cout << "if (a && b)" << std::endl;
    }

    if (a && c)
    {
        std::cout << "if (a && c)" << std::endl;
    }

    if (a || b)
    {
        std::cout << "if (a || b)" << std::endl;
    }

    if (b || d) // Не сработает
    {
        std::cout << "if (b || d)" << std::endl;
    }
}

// Последовательность проверки условий (Пример с классом)
void test2()
{
    struct SomeStruct
    {
        int a = 0;
        int b = 0;
    };

    SomeStruct* someStruct = nullptr;

    // Безопасная проверка полей. Если someStruct == nullptr, то дальнейшие вычисления не производятся
    if (someStruct && someStruct->a == 0 && someStruct->b == 0)
    {
        std::cout << "if (someStruct && someStruct->a == 0 && someStruct->b == 0)" << std::endl;
    }
}

// Последовательность проверки условий (Пример с функциями)
void test3()
{
    auto func = [](int a) {
        std::cout << "func(" << a << ")" << std::endl;
        return a % 2 == 0;
    };

    // func(4) и func(5) не будут вычисляться
    if (func(2) && func(3) && func(4) && func(5))
    {
        // ...
    }

    std::cout << "\n\n\n";

    // func(3) и func(4) не будут вычисляться
    if (func(1) || func(2) || func(3) || func(4))
    {
        // ...
    }
}

} // namespace Example1
