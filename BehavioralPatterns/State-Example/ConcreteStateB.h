#pragma once

#include "AbstractState.h"

/*!
 * \brief Конкретное состояние, которое имеет свою модель поведения
 */
class ConcreteStateB : public AbstractState
{
public:
    void handle1() override;
    void handle2() override;

};
