#pragma once

#include "Implementation.h"

/*
 * Управляющий класс, который использует конкретную реализацию (класс с логикой). Эти классы не зависят от
 * конкретной логики Implementation и работают с любым производным классом.
 *
 * (В данном примере класс не является абстрактным != Abstraction)
 */
class Abstraction
{
protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation);
    virtual ~Abstraction();

    virtual std::string operation() const;

};
