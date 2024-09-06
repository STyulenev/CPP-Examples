#include <iostream>

#include "Adapter.h"

int main()
{
    Target* target = new Target;
    std::cout << "Target: " << target->request() << std::endl;

    Adaptee* adaptee = new Adaptee;
    std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;

    Adapter* adapter = new Adapter(adaptee); // new Adapter();
    std::cout << "Adapter: " << adapter->request() << std::endl;

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
