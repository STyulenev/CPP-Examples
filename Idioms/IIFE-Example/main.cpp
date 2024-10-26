#include <iostream>
#include <functional>

#include "SomeClass.h"

/*
 * IIFE (Immediately-Invoked Function Expression) - немедленно вызываемое функциональное выражение. Представляет собой
 * лямбда-выражение, которое немедленно вызывается. Определяется как:
 *
 * []{ ... }();
 *
 * Это особенно полезно для преобразования серии операторов в выражение.
 */
int main()
{
    // Пример IIFE с простой лямбдой
    {
        const int var = [&] {
            int temp = 1;

            /* сложный код */

            temp *= 5;

            /* сложный код */

            return temp;
        }(); // Здесь происходит вызов лямбда-функции

        std::cout << "var = " << var << std::endl;
    }

    // Пример IIFE с простой лямбдой, но вынесенной отдельно
    {
        auto initialiser = [&] {
            int temp = 1;

            /* сложный код */

            temp *= 5;

            /* сложный код */

            return temp;
        }; // Здесь происходит вызов лямбда-функции

        const int var = initialiser();

        std::cout << "var = " << var << std::endl;
    }

    // Пример с std::invoke из <functional>
    {
        const int var = std::invoke([&] {
            int temp = 1;

            /* сложный код */

            temp *= 5;

            /* сложный код */

            return temp;
        });

        std::cout << "var = " << var << std::endl;
    }

    // Пример IIFE с лямбдой в списке инициализации конструктора
    {
        SomeClass someClass;

        std::cout << "var = " << someClass.getVar() << std::endl;
    }

    return 0;
}
