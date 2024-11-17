#include <iostream>

#include "Facade.h"

int main()
{
    SubSystem1* subsystem1 = new SubSystem1;
    SubSystem2* subsystem2 = new SubSystem2;

    Facade* facade = new Facade(subsystem1, subsystem2);

    std::cout << facade->operations();

    delete facade;

    return 0;
}
