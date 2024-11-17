#include <iostream>

#include "ConcreteClass1.h"
#include "ConcreteClass2.h"

int main()
{
    {
        std::cout << "Example 1:" << std::endl;
        ConcreteClass1* concreteClass1 = new ConcreteClass1;
        concreteClass1->TemplateMethod();
        delete concreteClass1;
    }

    std::cout << std::endl;

    {
        std::cout << "Example 2:" << std::endl;

        ConcreteClass2 *concreteClass2 = new ConcreteClass2;
        concreteClass2->TemplateMethod();

        delete concreteClass2;
    }

    return 0;
}
