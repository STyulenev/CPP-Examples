#include <iostream>

#include "FlyweightFactory.h"

/*
 * Легковес — это структурный паттерн, который экономит память, благодаря разделению общего состояния, вынесенного
 * в один объект, между множеством объектов.
 */

void clientCode(FlyweightFactory& ff,
                const std::string& plates, const std::string& owner, const std::string& brand,
                const std::string& model, const std::string& color)
{
    std::cout << std::endl;

    const Flyweight& flyweight = ff.getFlyweight({brand, model, color});
    flyweight.someAction({ owner, plates });

    std::cout << std::endl;
}

int main()
{
    // Создание фабрики легковесов с начальными данными
    FlyweightFactory* factory = new FlyweightFactory(
        {
            { "Chevrolet", "Camaro", "pink" },
            { "Mercedes Benz", "C300", "black" },
            { "Mercedes Benz", "C500", "red" },
            { "BMW", "M5", "red" },
            { "BMW", "X6", "white" }
        });

    factory->getListFlyweights();

    // Вставляем новые данные, среди которых есть уникальные данные
    clientCode(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
    clientCode(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");

    factory->getListFlyweights();
    delete factory;

    return 0;
}
