#pragma once

#include <string>

/*
 * Интерфейс для классов с реализацией, чья переопределенная логика будет использоваться в других классах.
 * Интерфейс предоставлят только чисто виртуальные методы для конкретных классов с
 * конкретной логикой.
 */
class Implementation
{
public:
    Implementation() {}
    virtual ~Implementation() {}

    virtual std::string someOperation() const = 0;

};
