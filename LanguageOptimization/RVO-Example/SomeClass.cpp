#include "SomeClass.h"

#include <iostream>

// Конструктор
SomeClass::SomeClass()
{
    std::cout << "SomeClass::SomeClass()"<< std::endl;
}

// Конструктор копирования
SomeClass::SomeClass(const SomeClass& copy) :
    SomeClass()
{
    std::cout << "SomeClass::SomeClass(const SomeClass& copy)"<< std::endl;
}

// Конструктор перемещения
SomeClass::SomeClass(SomeClass&& moved) noexcept
{
    std::cout << "SomeClass::SomeClass(SomeClass&& moved)" << std::endl;
}

// Копирующий оператор присваивания
SomeClass& SomeClass::operator=(const SomeClass& copy)
{
    std::cout << "SomeClass& SomeClass::operator=(const SomeClass& copy)" << std::endl;

    if (&copy != this) {
        // ...
    }

    return *this;
}

// Перемещающий оператор присваивания
SomeClass& SomeClass::operator=(SomeClass&& moved) noexcept
{
    std::cout << "SomeClass& SomeClass::operator=(SomeClass&& moved)" << std::endl;

    if (&moved != this) {
        // ...
    }

    return *this;
}

// Деструктор
SomeClass::~SomeClass()
{
    std::cout << "SomeClass::~SomeClass()" << std::endl;
}
