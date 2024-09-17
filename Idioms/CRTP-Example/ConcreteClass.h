#pragma once

#include "Base.h"

class ConcreteClass1 : public AbstractBase<ConcreteClass1>, public IBase
{
public:
    void implementation() override;

};

class ConcreteClass2 : public AbstractBase<ConcreteClass2>, public IBase
{
public:
    void implementation() override;

};
