#pragma once

#include "Implementation.h"

class ConcreteImplementationB : public Implementation
{
public:
    std::string operationImplementation() const override;

};
