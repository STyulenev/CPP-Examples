#pragma once

#include "Decorator.h"

/*
 * Конкретный декоратор, который добавляет дополнительное поведение к обычному декоратору.
 */
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA() = delete;
    ConcreteDecoratorA(AbstractComponent* component);
    ~ConcreteDecoratorA();

    std::string operation() const override;

};
