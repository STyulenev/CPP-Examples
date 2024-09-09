#include <iostream>

#include "ConcreteImplementationA.h"
#include "ConcreteImplementationB.h"
#include "ExtendedAbstraction.h"

void clientCode(const Abstraction& abstraction)
{
    // ...
    std::cout << abstraction.operation() << std::endl;
    // ...
}

int main()
{
    Implementation* implementation = new ConcreteImplementationA();
    Abstraction* abstraction = new Abstraction(implementation);
    clientCode(*abstraction);

    delete implementation;
    delete abstraction;

    std::cout << std::endl;

    implementation = new ConcreteImplementationB();
    abstraction = new ExtendedAbstraction(implementation);
    clientCode(*abstraction);

    delete implementation;
    delete abstraction;

    return 0;
}
