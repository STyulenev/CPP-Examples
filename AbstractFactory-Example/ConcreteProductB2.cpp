#include "ConcreteProductB2.h"

std::string ConcreteProductB2::usefulFunctionB() const
{
    return "The result of the product B2.";
}

std::string ConcreteProductB2::anotherUsefulFunctionB(const AbstractProductA &collaborator) const
{
    const std::string result = collaborator.usefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
}
