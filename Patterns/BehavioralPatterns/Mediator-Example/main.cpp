#include <iostream>

#include "ConcreteMediator.h"

int main()
{
    { // client code
        Component1* c1 = new Component1();
        Component2* c2 = new Component2();

        ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

        std::cout << "Client triggers task A." << std::endl;
        c1->doA();

        std::cout << "Client triggers task D." << std::endl;
        c2->doD();

        delete c1;
        delete c2;
        delete mediator;
    }

    return 0;
}
