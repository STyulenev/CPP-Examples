#pragma once

#include "SharedState.h"
#include "UniqueState.h"

/*!
 * \brief Класс-легковес хранит общую часть состояния, которая принадлежит нескольким реальным бизнес-объектам
 * и принимает уникальную часть объекта.
 */
class Flyweight
{
private:
    SharedState* sharedState_;

public:
    Flyweight(const SharedState* sharedState);
    Flyweight(const Flyweight& other);
    ~Flyweight();

    SharedState* sharedState() const;
    void someAction(const UniqueState& uniqueState) const;

};
