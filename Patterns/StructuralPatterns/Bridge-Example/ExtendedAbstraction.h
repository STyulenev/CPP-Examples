#pragma once

#include "Abstraction.h"

/*
 * Расширеный управляющий класс
 */
class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Implementation* implementation);
    ~ExtendedAbstraction();

    std::string operation() const override;

};
