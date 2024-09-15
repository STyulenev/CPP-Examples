#include <array>
#include <iostream>

#include "ConcreteComponentA.h"
#include "ConcreteComponentB.h"

#include "ConcreteVisitor1.h"
#include "ConcreteVisitor2.h"

void clientCode(std::array<const ComponentInterface*, 2> components, VisitorInterface* visitor)
{
    // ...
    for (const ComponentInterface* component : components) {
        component->someAction(visitor);
    }
    // ...
}

int main()
{
    std::array<const ComponentInterface *, 2> components = {new ConcreteComponentA(), new ConcreteComponentB()};

    std::cout << "The client code with ConcreteVisitor1" << std::endl;

    ConcreteVisitor1* visitor1 = new ConcreteVisitor1();
    clientCode(components, visitor1);

    std::cout << "The client code with ConcreteVisitor2" << std::endl;

    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2();
    clientCode(components, visitor2);

    for (const ComponentInterface* component : components) {
        delete component;
    }

    delete visitor1;
    delete visitor2;

    return 0;
}
