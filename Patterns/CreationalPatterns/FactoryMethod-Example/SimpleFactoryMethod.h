#pragma once

#include "ConcreteProduct1.h"
#include "ConcreteProduct2.h"

enum ProductType {
    CONCRETE_PRODUCT_1 = 0,
    CONCRETE_PRODUCT_2
    // ...
};

AbstractProduct* simpleFactoryMethod(const ProductType&& type);
