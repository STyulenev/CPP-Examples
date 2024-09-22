#pragma once

#include "IFirst.h"
#include "ISecond.h"

/*
 * Конкретная реализация №1
 */
class ConcreteClass1 : public IFirst, public ISecond
{
public:
    ConcreteClass1();
    ~ConcreteClass1();

    void method_1() const override;
    void method_2() override;
    //...

};
