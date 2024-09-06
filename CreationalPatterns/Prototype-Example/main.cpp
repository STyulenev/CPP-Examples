#include <iostream>

#include "PrototypeFactory.h"

void client(PrototypeFactory& prototypeFactory)
{
    std::cout << "Let's create a Prototype 1\n";

    AbstractPrototype* prototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->method(90);
    std::cout << "Adress " << prototype << "\n";
    delete prototype;

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototypeFactory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->method(10);
    std::cout << "Adress " << prototype << "\n";

    delete prototype;
}

int main()
{
    PrototypeFactory* prototypeFactory = new PrototypeFactory();

    client(*prototypeFactory);

    delete prototypeFactory;

    return 0;
}
