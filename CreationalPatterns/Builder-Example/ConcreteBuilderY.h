#pragma once

#include "AbstractBuilder.h"

/*
 * Конкретный класс-строитель с переопределенными методами, которые необходимы для построения класса-продукта
 */
class ConcreteBuilderY : public AbstractBuilder
{
public:
    ConcreteBuilderY();
    ~ConcreteBuilderY();

    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;
    // ...

};
