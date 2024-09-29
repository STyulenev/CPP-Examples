#include "ConcreteTarget.h"

ConcreteTarget::ConcreteTarget()
{
    std::cout << "ConcreteTarget::ConcreteTarget()" << std::endl;
}

ConcreteTarget::ConcreteTarget(const ConcreteTarget& copy)
{
    std::cout << "ConcreteTarget::ConcreteTarget(const ConcreteTarget& copy)" << std::endl;
}

ConcreteTarget::~ConcreteTarget()
{
    std::cout << "ConcreteTarget::~ConcreteTarget()" << std::endl;
}

ConcreteTarget* ConcreteTarget::create() const
{
    return new ConcreteTarget();
}

ConcreteTarget* ConcreteTarget::clone() const
{
    return new ConcreteTarget (*this);
}
