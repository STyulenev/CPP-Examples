#include "SomeClass.h"

#include <iostream>

/*
 * Copy-Elision - группа оптимизаций языка C++, которые позволяют устранить лишние операции копирования и перемещения объекта.
 * Частные случаи:
 * - RVO (см. RVO-Example);
 * - NRVO (см. NRVO-Example).
 *
 */

void test_1()
{
    SomeClass someClass;

    throw someClass;
}

SomeClass test_2()
{
    return SomeClass();
}

void test_3(SomeClass someClass)
{
    // ...
}

int main()
{
    { // Вызов двух конструктора, конструктора перемещения и копирования, и три деструктора (7 операции)
        try {
            test_1();
        } catch (SomeClass someClass) {
            // ...
        }
    }

    std::cout << std::endl;

    { // Вызов конструктора, конструктора перемещения и два деструктора (4 операции)
        try {
            test_1();
        } catch (const SomeClass& someClass) {
            // ...
        }
    }

    std::cout << std::endl;

    { // Вызов только конструктора и деструктора (всего 2 операции)
        test_3(test_2());
    }

    return 0;
}
