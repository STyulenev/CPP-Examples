#include <iostream>

#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

#include "AbstractProductA.h"
#include "AbstractProductB.h"

void clientCode(const AbstractFactory& factory)
{
    const AbstractProductA* productA = factory.createProductA();
    const AbstractProductB* productB = factory.createProductB();

    std::cout << productB->usefulFunctionB() << std::endl;
    std::cout << productB->anotherUsefulFunctionB(*productA) << std::endl;

    delete productA;
    delete productB;
}

int main()
{
    std::cout << "Client: Testing client code with the first factory type:" << std::endl;
    ConcreteFactory1* f1 = new ConcreteFactory1();
    clientCode(*f1);
    delete f1;

    std::cout << "Client: Testing the same client code with the second factory type:" << std::endl;
    ConcreteFactory2* f2 = new ConcreteFactory2();
    clientCode(*f2);
    delete f2;

    return 0;
}
