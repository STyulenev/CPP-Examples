#include "Objects.h"

#include <iostream>

IObject::~IObject()
{
    delete data;
}

void IObject::someAction()
{
    // Данный метод скрывает проверку на null, чтобы клиентский код был более удобен
    if (data) {
        std::cout << "Data:\n  1. " << data->first << "\n  2. " << data->secont << std::endl;
    } else {
        std::cout << "Data:\n  1. null\n  2. null" << std::endl;
    }
}

ConcreteObject1::ConcreteObject1()
{
    data = new Data();

    data->first = "ConcreteObject1";
    data->secont = 11;
}

ConcreteObject2::ConcreteObject2()
{
    data = new Data();

    data->first = "ConcreteObject2";
    data->secont = 12;
}

NullObject::NullObject()
{
    // В нулевой реализации ничего не делаем, чтобы data == nullptr
    // ...
}
