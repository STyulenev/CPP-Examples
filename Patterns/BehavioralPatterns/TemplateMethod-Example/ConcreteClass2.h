#pragma once

#include "AbstractClass.h"

/*!
 * \brief Конкретный класс может изменять необходимые методы
 */
class ConcreteClass2 : public AbstractClass
{
protected:
    void requiredAction1() const override;
    void requiredAction2() const override;
    void optionalAction1() const override;

};
