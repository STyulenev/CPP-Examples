#include "PrototypeFactory.h"

#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

PrototypeFactory::PrototypeFactory()
{
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
}

PrototypeFactory::~PrototypeFactory()
{
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
}

AbstractPrototype* PrototypeFactory::CreatePrototype(Type type)
{
    return prototypes_[type]->clone();
}
