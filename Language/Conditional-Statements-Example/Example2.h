#pragma once

#include <iostream>

/*
 * Тернарный оператор
 */

namespace Example2 {

// Простое вычисление результата
void test1()
{
    int x = true ? 1 : 2;
    int y = false ? 1 : 2;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

// Выбор переменной
void test2()
{
    int x = 0;
    int y = 0;

    (true ? x : y) = 1;
    (false ? x : y) = 2;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

} // namespace Example2
