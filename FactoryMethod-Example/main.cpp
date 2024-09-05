#include <iostream>

#include "ConcreteCreator1.h"
#include "ConcreteCreator2.h"

//#include "SimpleFactoryMethod.h"

void clientCode(const Creator& creator)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n" << creator.someOperation() << std::endl;
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator1(); // or simpleFactoryMethod(ProductType::CONCRETE_PRODUCT_1);
    clientCode(*creator);

    std::cout << std::endl;

    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2(); // or simpleFactoryMethod(ProductType::CONCRETE_PRODUCT_2);
    clientCode(*creator2);

    delete creator;
    delete creator2;

    return 0;
}
