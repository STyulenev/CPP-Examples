#pragma once

#include "Implementation.h"

/*
 * Конкретный класс из иерархии реализации
 */
class ConcreteImplementationA : public Implementation
{
public:
    ConcreteImplementationA();
    ~ConcreteImplementationA();

    std::string someOperation() const override;

};
