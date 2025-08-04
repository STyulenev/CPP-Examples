#pragma once

#include <iostream>

/*
 * Использование анонимных объединений
 *
 * Можно создать анонимное объединение прямо внутри структуры или класса, чтобы избежать явного обращения к имени объединения.
 * Такое решение упрощает обращение к данным и делает код лаконичнее.
 *
 */
namespace Example3
{

struct Point
{
    bool polar;

    union
    {
        struct
        {
            double x;
            double y;
        };

        struct
        {
            double r;
            double theta;
        };
    };
};

void test()
{
    Point p;
    p.polar = false;
    p.x = 1.0;
    p.y = 2.0;

    if (!p.polar) {
        std::cout << "Cartesian coordinates: (" << p.x << ", " << p.y << ")" << std::endl;
    } else {
        std::cout << "Polar coordinates: (" << p.r << ", " << p.theta << ")" << std::endl;
    }
}

} // namespace Example3
