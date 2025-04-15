#include <iostream>

#include "ConcreteComponent.h"

#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

/*
 * Декоратор — это структурный паттерн, который позволяет добавлять объектам новые поведения на лету, помещая их в объекты-обёртки.
 */

void clientCode(AbstractComponent* component)
{
    // ...
    std::cout << "RESULT: " << component->operation() << std::endl;
    // ...
}

int main()
{
    AbstractComponent* simple = new ConcreteComponent();

    clientCode(simple); // Простой компонент

    AbstractComponent* decorator1 = new ConcreteDecoratorA(simple);     // Добавили обёртку
    AbstractComponent* decorator2 = new ConcreteDecoratorB(decorator1); // Добавили обёртку

    clientCode(decorator2); // Усложнённый компонент

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
