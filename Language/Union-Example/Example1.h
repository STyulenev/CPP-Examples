#pragma once

#include <iostream>

/*
 * Простое объединение нескольких простых типов данных.
 *
 * Простейший способ использования объединения — хранение различных примитивных типов данных в одном месте. Здесь объединением
 * управляют вручную, меняя доступ к полям в зависимости от текущего типа данных.
 *
 */
namespace Example1
{

union SimpleUnion // 4 байта
{
    int i;   // 4 байта
    float f; // 4 байта
};

void test()
{
    SimpleUnion u;

    std::cout << "union size = " << sizeof(u) << std::endl;

    u.i = 10;
    std::cout << "Integer value: " << u.i << std::endl;
    std::cout << "Float value: "   << u.f << std::endl; // UB

    u.f = 3.14f;
    std::cout << "Float value: "   << u.f << std::endl;
    std::cout << "Integer value: " << u.i << std::endl; // UB
}

} // namespace Example1
