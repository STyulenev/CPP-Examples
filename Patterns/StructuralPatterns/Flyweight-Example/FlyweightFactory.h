#pragma once

#include <unordered_map>

#include "Flyweight.h"

/*!
 * \brief Фабрика легковесов. Возвращает существующий или создаёт новый по запросу
 */
class FlyweightFactory
{
private:
    /*!
     * \brief Карта с легковесами
     */
    std::unordered_map<std::string, Flyweight> flyweights_;

public:
    FlyweightFactory(std::initializer_list<SharedState> shareStates);

    /**
   * Возвращает существующий Легковес с заданным состоянием или создает новый.
   */
    Flyweight getFlyweight(const SharedState& sharedЫtate);
    /*!
     * \brief Список класов-легковесов
     */
    void getListFlyweights() const;

private:
    /*!
     * \brief Метод с получения хеша состояния
     */
    std::string getHash(const SharedState& sharedState) const;
};
