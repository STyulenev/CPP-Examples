#include <iostream>

#include "Adapter.h"

/*
 * Адаптер – это структурный паттерн проектирования, который позволяет объектам с несовместимыми интерфейсами работать вместе.
 */

int main()
{
    // Результат работы целевого класса
    Target* target = new Target();
    std::cout << "Target: " << target->someAction() << std::endl;

    // Результат работы адаптируемого класса
    Adaptee* adaptee = new Adaptee();
    std::cout << "Adaptee: " << adaptee->specialAction() << std::endl;

    // Результат работы адаптера - некоторая обработка адаптируемого и целового классов
#if (MULTIPLE_INHERITANCE)
    Adapter* adapter = new Adapter(adaptee);
#else
    Adapter* adapter = new Adapter();
#endif
    std::cout << "Adapter: " << adapter->someAction() << std::endl;

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
