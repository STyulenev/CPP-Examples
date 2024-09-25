#pragma once

#include "Product.h"

/*
 * Абстрактный класс-строитель. Содержит в себе продукт и виртуальные методы,
 * которые следует переопределить в конкретном классе-строителе.
 */
class AbstractBuilder
{
public:
    AbstractBuilder() {}
    virtual ~AbstractBuilder() {}

    Product get() {
        return product;
    }

    /*
     * Методы построения продукта. Аналогичные методы вызываются у класса-продукта
     */
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    // ...

protected:
    Product product;

};
