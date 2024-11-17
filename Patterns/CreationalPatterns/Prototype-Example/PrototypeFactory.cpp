#include "PrototypeFactory.h"

#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

#include <iostream>

PrototypeFactory::PrototypeFactory()
{
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);

    std::cout << "Adress real PROTOTYPE_1: " << prototypes_[Type::PROTOTYPE_1] << std::endl;
    std::cout << "Adress real PROTOTYPE_2: " << prototypes_[Type::PROTOTYPE_2] << std::endl;
}

PrototypeFactory::~PrototypeFactory()
{
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
}

AbstractPrototype* PrototypeFactory::сreatePrototype(Type type)
{
    return prototypes_[type]->clone();
}
