#pragma once

#include "AbstractPrototype.h"

#include <unordered_map>

/*
 * Фабрика по копированию классов
 */
class PrototypeFactory
{
private:
    /*
     * Все класс-прототипы уже созданы и копируются по запросу
     */
    std::unordered_map<Type, AbstractPrototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory();
    ~PrototypeFactory();

    /*
     * Метод для получения копии
     */
    AbstractPrototype* сreatePrototype(Type type);

};
