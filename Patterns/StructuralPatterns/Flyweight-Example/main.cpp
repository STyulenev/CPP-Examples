#include <iostream>

#include "FlyweightFactory.h"

void clientCode(FlyweightFactory& ff,
                const std::string& plates, const std::string& owner, const std::string& brand,
                const std::string& model, const std::string& color)
{
    std::cout << "Client code ..." << std::endl;
    const Flyweight& flyweight = ff.getFlyweight({brand, model, color});
    flyweight.someAction({owner, plates});
}

int main()
{
    // Создание фабрики легковесов с начальными данными
    FlyweightFactory* factory = new FlyweightFactory(
        {
            { "Chevrolet", "Camaro2018", "pink" },
            { "Mercedes Benz", "C300", "black" },
            { "Mercedes Benz", "C500", "red" },
            { "BMW", "M5", "red" },
            { "BMW", "X6", "white" }
        });

    factory->getListFlyweights();

    clientCode(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
    clientCode(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");

    factory->getListFlyweights();
    delete factory;

    return 0;
}
