#include <iostream>

#include "PrototypeFactory.h"

/*
 * Порождающий паттерн Прототип (Prototype). Главная задача паттерна копировать по запросу уже созданный набор
 * классов-прототипов (со своим набором данных).
 */

void test(PrototypeFactory* prototypeFactory)
{
    {
        std::cout << "Create ConcretePrototype1:" << std::endl;

        AbstractPrototype* prototype1 = prototypeFactory->сreatePrototype(Type::PROTOTYPE_1);
        prototype1->method(90);
        std::cout << "Adress copy: " << prototype1 << std::endl;
        delete prototype1;
    }

    {
        std::cout << "Create ConcretePrototype2:" << std::endl;

        AbstractPrototype* prototype2 = prototypeFactory->сreatePrototype(Type::PROTOTYPE_2);
        prototype2->method(10);
        std::cout << "Adress copy: " << prototype2 << std::endl;

        delete prototype2;
    }
}

int main()
{
    PrototypeFactory* prototypeFactory = new PrototypeFactory();

    test(prototypeFactory);

    delete prototypeFactory;

    return 0;
}
