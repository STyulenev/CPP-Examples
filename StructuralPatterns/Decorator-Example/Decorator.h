#pragma once

#include "AbstractComponent.h"

class Decorator : public AbstractComponent
{
protected:
    AbstractComponent* component_;

public:
    Decorator(AbstractComponent* component);

    std::string operation() const override;

};
