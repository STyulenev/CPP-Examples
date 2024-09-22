#pragma once

#include "IFirst.h"

/*
 * Конкретная реализация №2
 */
class ConcreteClass2 : public IFirst
{
public:
    ConcreteClass2();
    ~ConcreteClass2();

    void method_1() const override;
    //...
};
