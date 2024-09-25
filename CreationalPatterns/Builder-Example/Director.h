#pragma once

#include "AbstractBuilder.h"

/*
 * Класс-директор строит объект класса-продукта в зависимости от класса-строителя
 */
class Director
{
public:
    Director();
    ~Director();

    void set(AbstractBuilder* builder);
    Product get();

    void construct();
    // ...

private:
    AbstractBuilder* builder;

};
