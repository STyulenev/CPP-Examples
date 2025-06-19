#pragma once

#include <iostream>

/*
 * consteval — ключевое слово в C++, которое используется для объявления функций, гарантированно оцениваемых во время компиляции.
 * Такие функции известны как немедленные функции. Попытка вызвать функцию consteval во время выполнения приведёт к ошибке компиляции.
 * Consteval полезен, когда нужно гарантировать выполнение определённых операций на этапе компиляции, например, для генерации постоянных
 * значений или проведения статических проверок.
 */

namespace Example4 {

consteval int square(int x)
{
    return x * x;
}

void test1()
{
    std::cout << "\ntest1()\n\n";

    // Вычисляется на этапе компиляции
    // constexpr int result = square(5);
    // const int result = square(5);
    int result = square(5);

    // Ошибка
    // int x = 3;
    // int result = square(x);

    std::cout << "Square of 5 is: " << result << std::endl;
}

void test2()
{
    std::cout << "\ntest2()\n\n";

    // Ошибка
    // int x = 3;
    // int result = square(x);

    const int x = 3;
    int result = square(x);

    std::cout << "Square of 3 is: " << result << std::endl;
}

} // namespace Example4
