#pragma once

#include <string>

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class AbstractPrototype
{
protected:
    std::string prototypeName_;
    float prototypeField_;

public:
    AbstractPrototype();
    AbstractPrototype(std::string prototypeName);
    virtual ~AbstractPrototype();

    virtual AbstractPrototype* clone() const = 0;
    virtual void method(float prototypeField);

};
