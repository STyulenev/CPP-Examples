#pragma once

#include <iostream>

int x = 42; // глобальная переменная

/*
 * Скрытие имени в блоках и функциях
 */

namespace Example1
{

// int x = 42; // нельзя

void test()
{
    int x = 5; // локальная переменная, скрывает глобальную x

    std::cout << "local = " << x << "\n";
    std::cout << "global = " << ::x << "\n";
}

} // namespace Example1
