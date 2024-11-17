#pragma once

#include "Implementation.h"

/*
 * Конкретный класс из иерархии реализации
 */
class ConcreteImplementationB : public Implementation
{
public:
    ConcreteImplementationB();
    ~ConcreteImplementationB();

    std::string someOperation() const override;

};
