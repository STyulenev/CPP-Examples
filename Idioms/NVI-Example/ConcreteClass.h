#pragma once

#include "IBase.h"

class ConcreteClass : public IBase
{
public:
    ConcreteClass();
    ~ConcreteClass();

private:
    void someActionImpl() override;

};
