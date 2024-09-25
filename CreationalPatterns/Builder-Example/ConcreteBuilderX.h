#pragma once

#include "AbstractBuilder.h"

/*
 * Конкретный класс-строитель с переопределенными методами, которые необходимы для построения класса-продукта
 */
class ConcreteBuilderX : public AbstractBuilder
{
public:
    ConcreteBuilderX();
    ~ConcreteBuilderX();

    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;
    // ...

};
