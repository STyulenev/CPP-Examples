#pragma once

#include "Implementation.h"

class ConcreteImplementationA : public Implementation
{
public:
    std::string operationImplementation() const override;

};
