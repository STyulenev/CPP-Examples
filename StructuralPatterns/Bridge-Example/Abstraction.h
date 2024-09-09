#pragma once

#include "Implementation.h"

class Abstraction
{
protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation);

    virtual ~Abstraction();

    virtual std::string operation() const;

};
