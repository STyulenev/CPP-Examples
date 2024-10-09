#include <iostream>

#include "SomeClass.h"

int main()
{
    SomeClass a;
    a = "A";

    std::cout << std::endl << std::endl;

    SomeClass b = "B";
    a = b;

    std::cout << std::endl << std::endl;

    SomeClass c(a);

    std::cout << std::endl << std::endl;

    SomeClass d("D");

    return 0;
}
