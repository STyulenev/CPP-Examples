#pragma once

#include "AbstractPrototype.h"

/*
 * Конкретный класс-прототип
 */
class ConcretePrototype1 : public AbstractPrototype
{
private:
    float concretePrototypeField1_;

public:
    ConcretePrototype1();
    ConcretePrototype1(std::string prototypeName, float concretePrototypeField);
    ~ConcretePrototype1();

    /*
     * Метод для копирования текущего экземпляра класса
     */
    AbstractPrototype* clone() const override;

};
