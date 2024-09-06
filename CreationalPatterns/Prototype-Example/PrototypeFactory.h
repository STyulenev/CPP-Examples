#pragma once

#include "AbstractPrototype.h"

#include <unordered_map>

class PrototypeFactory
{
private:
    std::unordered_map<Type, AbstractPrototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory();
    ~PrototypeFactory();

    AbstractPrototype *CreatePrototype(Type type);

};
