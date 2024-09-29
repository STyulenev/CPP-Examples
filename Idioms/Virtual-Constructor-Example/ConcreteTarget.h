#pragma once

#include "AbstractTarget.h"

/*
 * Конкретный класс, который переопределяет виртуальные методы со своим возвращаемым типом (ковариантный тип возврата).
 */
class ConcreteTarget : public AbstractTarget
{
public:
    ConcreteTarget();
    ConcreteTarget(const ConcreteTarget& copy);

    virtual ~ConcreteTarget();

    ConcreteTarget* create() const override; // ~Виртуальный конструктор
    ConcreteTarget* clone() const override;  // ~Виртуальный конструктор копирования

};
