#pragma once

#include "Abstraction.h"

class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Implementation* implementation);

    std::string operation() const override;

};
