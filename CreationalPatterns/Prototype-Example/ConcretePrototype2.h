#pragma once

#include "AbstractPrototype.h"

/*
 * Конкретный класс-прототип
 */
class ConcretePrototype2 : public AbstractPrototype
{
private:
    float concretePrototypeField2_;

public:
    ConcretePrototype2();
    ConcretePrototype2(std::string prototypeName, float concretePrototypeField);
    ~ConcretePrototype2();

    /*
     * Метод для копирования текущего экземпляра класса
     */
    AbstractPrototype* clone() const override;

};
