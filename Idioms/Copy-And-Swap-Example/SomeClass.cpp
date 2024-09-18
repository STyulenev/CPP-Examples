#include "SomeClass.h"

#include <iostream>

// Перегрузка конструктора
SomeClass::SomeClass(std::string data) :
    text(new std::string(data))
{
    id = ++counter;
    std::cout << "Create SomeClass.text " << id << std::endl;
}

// Конструктор копирования
SomeClass::SomeClass(const SomeClass& copy) :
    SomeClass(copy.getText())
{
    std::cout << "Copy SomeClass.text " << copy.id << " to " << id << std::endl;
}

// Конструктор перемещения
SomeClass::SomeClass(SomeClass&& moved) noexcept :
    text(moved.text)
{
    id = ++counter;

    std::cout << "Move SomeClass.text " << moved.id << " to " << id << std::endl;

    moved.text = nullptr; // Обнулили текстовое поле у перемещаемого класса
}

// Копирующий оператор присваивания
SomeClass& SomeClass::operator=(const SomeClass& copy)
{
    std::cout << "Copy assign SomeClass.text " << copy.id << " to " << id << std::endl;

    try {
        if (&copy != this) { // Проверка на самоприсваивание
            // Copy-And-Swap идиома
            SomeClass temp{copy}; // создаем временную копию через конструктор копирования
            swap(*this, temp);    // обмен значениями
        }
    } catch (...) {
        std::cout << "Error" << id << std::endl;
    }

    return *this;
}

// Перемещающий оператор присваивания
SomeClass& SomeClass::operator=(SomeClass&& moved) noexcept
{
    std::cout << "Move assign SomeClass.text " << moved.id << " to " << id << std::endl;

    if (&moved != this) { // Проверка на самоприсваивания
        delete text;          // освобождаем память текущего объекта
        text = moved.text;    // копируем указатель из перемещаемого объекта в текущий
        moved.text = nullptr; // сбрасываем значение указателя в перемещаемом объекте
    }

    return *this; // возвращаем текущий объект
}

// Деструктор
SomeClass::~SomeClass()
{
    std::cout << "Delete SomeClass.text " << id << std::endl;

    delete text; // освобождаем память
}

void swap(SomeClass &lhs, SomeClass &rhs) noexcept
{
    std::swap(lhs.text, rhs.text); // обмениваем поля текст
    // ...
}

const std::string& SomeClass::getText() const
{
    return *text;
}

unsigned int SomeClass::getId() const
{
    return id;
}
