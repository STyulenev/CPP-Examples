#pragma once

#include "Decorator.h"

/*
 * Конкретный декоратор, который добавляет дополнительное поведение к обычному декоратору.
 */
class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB() = delete;
    ConcreteDecoratorB(AbstractComponent* component);
    ~ConcreteDecoratorB();

    std::string operation() const override;

};
