#include <iostream>

#include "Iterator.h"
#include "Container.h"
#include "CustomClass.h"

int main()
{
    {
        Container<int> container;

        container.add(1);
        container.add(3);
        container.add(5);
        container.add(7);
        container.add(9);

        Iterator<int, Container<int>>* it = container.createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            std::cout << *it->current() << std::endl;
        }

        delete it;
    }

    std::cout << std::endl;

    {
        Container<CustomClass> container;

        CustomClass first(1);
        CustomClass second(2);
        CustomClass third(3);

        container.add(first);
        container.add(second);
        container.add(third);

        Iterator<CustomClass, Container<CustomClass>>* it2 = container.createIterator();
        for (it2->first(); !it2->isDone(); it2->next()) {
            std::cout << it2->current()->getData() << std::endl;
        }

        delete it2;
    }

    return 0;
}
