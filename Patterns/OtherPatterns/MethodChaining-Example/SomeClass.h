#pragma once

#include <iostream>

/*
 * Method Chaining (Цепочка методов) в C++ — это когда метод возвращает ссылку на объект-владелец,
 * чтобы можно было вызвать другой метод.
 */
class SomeClass
{
private:
    float       m_first;
    int         m_second;
    std::string m_third;

public:
    SomeClass();
    ~SomeClass();

    // Пример с полями
    SomeClass& setFirstField(const float first);
    SomeClass& setSecondField(const int second);
    SomeClass& setThirdField(const std::string&& third);

    // Пример с operator<<
    SomeClass& operator<<(const std::string&& data);

    friend std::ostream& operator<<(std::ostream& os, const SomeClass& someClass) {
        os << "SomeClass: first = " << someClass.m_first
           << ", second = " << someClass.m_second
           << ", third = " << someClass.m_third;

        return os;
    }

};
