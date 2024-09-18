#pragma once

#include <string>

class SomeClass
{
public:
    SomeClass() = delete;                             // Конструктор по умолчанию (удалён)
    SomeClass(std::string data);                      // Перегрузка конструктора
    SomeClass(const SomeClass& copy);                 // Конструктор копирования
    SomeClass(SomeClass&& moved) noexcept;            // Конструктор перемещения
    SomeClass& operator=(const SomeClass& copy);      // Копирующий оператор присваивания
    SomeClass& operator=(SomeClass&& moved) noexcept; // Перемещающий оператор присваивания
    ~SomeClass();                                     // Деструктор

    friend void swap(SomeClass& lhs, SomeClass& rhs) noexcept; // Функция обмена

    const std::string& getText() const;
    unsigned int getId() const;

private:
    std::string* text;  // Некоторый текст
    unsigned int id{};  // Идентификатор класса

    static inline unsigned counter{}; // Счётчик количества объектов

};
