#include <iostream>

#include "SomeClass.h"

/*
 * Move-семантика в C++ позволяет избежать копирования объектов путём передачи ресурсов от одного объекта к другому. Используется
 * для оптимизации производительности при работе с временными объектами или большими структурами данных. Она реализуется с помощью
 * rvalue-ссылок и специального конструктора перемещения. Move-семантику следует использовать, когда требуется передать владение ресурсами,
 * например, в контейнерах стандартной библиотеки, чтобы минимизировать накладные расходы на копирование.
 *
 */

void func1([[maybe_unused]] SomeClass someClass)
{
    std::cout << "func #1" << std::endl;
}

void func2([[maybe_unused]] SomeClass& someClass)
{
    std::cout << "func #2" << std::endl;
}

void func3([[maybe_unused]] SomeClass&& someClass)
{
    std::cout << "func #3" << std::endl;
}

int main()
{
    {
        SomeClass someClass;
        func1(someClass);
    }

    std::cout << std::endl;

    {
        SomeClass someClass;
        func1(std::move(someClass));
    }

    std::cout << std::endl;

    {
        SomeClass someClass;
        func2(someClass);
    }

    std::cout << std::endl;

    {
        SomeClass someClass;
        func3(std::move(someClass));
    }

    return 0;
}
