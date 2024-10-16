#include <iostream>

#include "ConcreteImplementationA.h"
#include "ConcreteImplementationB.h"
#include "ExtendedAbstraction.h"

/*
 * Мост – это структурный паттерн проектирования, который разделяет один или несколько классов на две
 * отдельные иерархии – абстракцию и реализацию (т.е. управляющие классы и классы с логикой),
 * позволяя изменять их независимо друг от друга.
 *
 *                               Implementation
 * Abstraction                   ConcreteImplementationA
 * ExtendedAbstraction   <===>   ConcreteImplementationB
 * ...                           ...
 *
 */

int main()
{
    Implementation* implementation = new ConcreteImplementationA();
    Abstraction* abstraction = new Abstraction(implementation);

    std::cout << abstraction->operation() << std::endl;

    delete implementation;
    delete abstraction;

    std::cout << std::endl;

    implementation = new ConcreteImplementationB();
    abstraction = new ExtendedAbstraction(implementation);

    std::cout << abstraction->operation() << std::endl;

    delete implementation;
    delete abstraction;

    return 0;
}
