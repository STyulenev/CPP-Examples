#pragma once

#include <string>

/*
 * Адаптируемый класс, который имеет полезную нагрузку, но её требуется доработать.
 */
class Adaptee
{
public:
    Adaptee();
    virtual ~Adaptee();

    std::string specialAction() const;

};
