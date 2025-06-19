#pragma once

#include <iostream>

/*
 * Ключевое слово const в C++ определяет постоянные значения, которые не могут быть изменены во время выполнения программы. Как
 * только значение или функция объявляются как постоянные, их значение становится фиксированным, и если попытаться его изменить,
 * выдаётся ошибка.
 */

namespace Example1 {

const int globalVar = 200; // Инициализация во время выполнения

void test1()
{
    std::cout << "\ntest1()\n\n";

    // globalVar = 300; // Ошибка

    std::cout << "globalVar = " << globalVar << std::endl;
}

void test2()
{
    std::cout << "\ntest2()\n\n";

    // int *pia = const_cast<int*>(&globalVar); // Ошибка, глобальную константу нельзя изменять

    const int var = 5;
    int* pv = const_cast<int*>(&var);
    *pv = 50;

    std::cout << &var << "\t" <<  pv << std::endl;
    std::cout <<  var << "\t" << *pv << std::endl;
}

} // namespace Example1
