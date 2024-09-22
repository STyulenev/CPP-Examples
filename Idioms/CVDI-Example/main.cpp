#include "ConcreteClass.h"

#include <iostream>

int main()
{
    auto data = factory<ConcreteClass>(5);

    std::cout << "... code ..." << std::endl;
    // ...

    return 0;
}
