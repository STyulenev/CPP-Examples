#pragma once

#include "AbstractClass.h"

/*!
 * \brief Конкретный класс может изменять необходимые методы
 */
class ConcreteClass1 : public AbstractClass
{
protected:
    void requiredAction1() const override;
    void requiredAction2() const override;

};
