#pragma once

#include "AbstractBase.h"

/*
 * Конкретная реализация класса-клиента от AbstractBase
 */
class ConcreteClass : public AbstractBase
{
private:
    virtual void action1(int value);
    virtual void action2();
    // ...

public:
    ConcreteClass();
    ~ConcreteClass();
};
