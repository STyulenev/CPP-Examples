#include "SimpleFactoryMethod.h"

#include <iostream>

AbstractProduct* simpleFactoryMethod(const ProductType&& type)
{
    switch (type) {
    case CONCRETE_PRODUCT_1:
        return new ConcreteProduct1();
    case CONCRETE_PRODUCT_2:
        return new ConcreteProduct2();
    default:
        std::cout << "Error" << std::endl;
    }

    throw std::runtime_error("...");
}
