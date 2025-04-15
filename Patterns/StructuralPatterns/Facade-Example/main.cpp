#include <iostream>

#include "Facade.h"

/*
 * Фасад — это структурный паттерн проектирования, который предоставляет простой интерфейс к сложной системе классов, библиотеке или фреймворку
 */

int main()
{
    SubSystem1* subsystem1 = new SubSystem1(); // Объект подсистемы #1
    SubSystem2* subsystem2 = new SubSystem2(); // Объект подсистемы #2

    Facade* facade = new Facade(subsystem1, subsystem2); // Класс-фасад, который объединил подсистемы для комфортной работы

    std::cout << facade->operations();

    delete facade;

    return 0;
}
