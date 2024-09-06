#include "ConcreteProductB1.h"

std::string ConcreteProductB1::usefulFunctionB() const
{
    return "The result of the product B1.";
}

std::string ConcreteProductB1::anotherUsefulFunctionB(const AbstractProductA& collaborator) const
{
    const std::string result = collaborator.usefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
}
