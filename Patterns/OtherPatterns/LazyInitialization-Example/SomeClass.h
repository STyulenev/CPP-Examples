#pragma once

#include <iostream>

class SomeClass
{
public:
    SomeClass();
    ~SomeClass();

    // Метод отложенной инициализации
    void launch();

    friend std::ostream& operator<<(std::ostream& os, const SomeClass& someClass) {
        os << "SomeClass: first = " << someClass.m_first
           << ", second = " << someClass.m_second
           << ", third = " << someClass.m_third;

        return os;
    }

private:
    float       m_first;
    int         m_second;
    std::string m_third;

};
