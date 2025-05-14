#include "SomeClass.h"

#include <iostream>

// Конструктор
SomeClass::SomeClass()
{
    std::cout << "SomeClass::SomeClass" << std::endl;
}

// Конструктор копирования
SomeClass::SomeClass([[maybe_unused]] const SomeClass& copy)
{
    std::cout << "SomeClass::SomeClass(const SomeClass& copy)" << std::endl;
}

// Конструктор перемещения
SomeClass::SomeClass([[maybe_unused]] SomeClass&& moved) noexcept
{
    std::cout << "SomeClass::SomeClass(SomeClass&& moved)" << std::endl;
}

// Копирующий оператор присваивания
SomeClass& SomeClass::operator=([[maybe_unused]] const SomeClass& copy)
{
    std::cout << "SomeClass& SomeClass::operator=(const SomeClass& copy)" << std::endl;

    try {
        //this->a = copy.a;
        //this->b = copy.b;
        // ...
    } catch (...) {
        std::cout << "Error" << std::endl;
    }

    return *this;
}

// Перемещающий оператор присваивания
SomeClass& SomeClass::operator=(SomeClass&& moved) noexcept
{
    std::cout << "SomeClass& SomeClass::operator=(SomeClass&& moved)" << std::endl;

    if (&moved != this) { // Проверка на самоприсваивание
        // Удаление полей в moved
        // ...
    }

    return *this; // возвращаем текущий объект
}

// Деструктор
SomeClass::~SomeClass()
{
    std::cout << "SomeClass::~SomeClass()" << std::endl;
}

void swap([[maybe_unused]] SomeClass &lhs, [[maybe_unused]] SomeClass &rhs) noexcept
{
    //std::swap(lhs.a, rhs.a);
    //std::swap(lhs.b, rhs.b);
    // ...
}

