#pragma once

#include "AbstractComponent.h"

class ConcreteComponent : public AbstractComponent
{
public:
    std::string operation() const override;

};
