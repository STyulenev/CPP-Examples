#pragma once

#include <unordered_map>

#include "Flyweight.h"

/*
 * Фабрика легковесов. Возвращает существующий или создаёт новый по запросу
 */
class FlyweightFactory
{
private:
    /*
     * Карта с легковесами
     */
    std::unordered_map<std::string, Flyweight> flyweights_;

public:
    FlyweightFactory() = delete;
    FlyweightFactory(std::initializer_list<SharedState> shareStates);
    ~FlyweightFactory();

    /*
     * Возвращает существующий Легковес с заданным состоянием или создает новый.
     */
    Flyweight getFlyweight(const SharedState& sharedЫtate);

    /*
     * Список класов-легковесов
     */
    void getListFlyweights() const;

private:
    /*
     * Метод с получения хеша состояния
     */
    std::string getHash(const SharedState& sharedState) const;

};
