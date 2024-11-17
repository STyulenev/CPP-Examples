#include <iostream>

#include "ConcreteComponent.h"

#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

void clientCode(AbstractComponent* component)
{
    // ...
    std::cout << "RESULT: " << component->operation() << std::endl;
    // ...
}

int main()
{
    AbstractComponent* simple = new ConcreteComponent();
    std::cout << "Client: I've got a simple component:" << std::endl;
    clientCode(simple);

    AbstractComponent* decorator1 = new ConcreteDecoratorA(simple);
    AbstractComponent* decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Now I've got a decorated component:" << std::endl;
    clientCode(decorator2);

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
