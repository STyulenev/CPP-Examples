#include "SomeClass.h"

SomeClass::SomeClass()
{
    // ...
}

SomeClass::~SomeClass()
{
    // ...
}

SomeClass& SomeClass::setFirstField(const float first)
{
    if (first != m_first)
        m_first = first;

    return *this;
}

SomeClass& SomeClass::setSecondField(const int second)
{
    if (second != m_second)
        m_second = second;

    return *this;
}

SomeClass& SomeClass::setThirdField(const std::string&& third)
{
    if (third != m_third)
        m_third = third;

    return *this;
}

SomeClass &SomeClass::operator<<(const std::string&& data)
{
    m_third += data;
    return *this;
}
