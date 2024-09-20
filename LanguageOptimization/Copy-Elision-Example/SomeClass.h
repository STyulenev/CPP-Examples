#pragma once

class SomeClass
{
public:
    SomeClass();                                      // Конструктор
    SomeClass(const SomeClass& copy);                 // Конструктор копирования
    SomeClass(SomeClass&& moved) noexcept;            // Конструктор перемещения
    SomeClass& operator=(const SomeClass& copy);      // Копирующий оператор присваивания
    SomeClass& operator=(SomeClass&& moved) noexcept; // Перемещающий оператор присваивания
    ~SomeClass();                                     // Деструктор

};
