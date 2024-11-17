#include <iostream>

#include "Director.h"

#include "ConcreteBuilderX.h"
#include "ConcreteBuilderY.h"

int main()
{
    Director director;
    director.set(new ConcreteBuilderX());
    director.construct();

    Product product1 = director.get();
    std::cout << "First product: " << product1.get() << std::endl;

    director.set(new ConcreteBuilderY());
    director.construct();

    Product product2 = director.get();
    std::cout << "Second product: " << product2.get() << std::endl;

    return 0;
}
