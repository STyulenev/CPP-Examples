#pragma once

#include "AbstractComponent.h"

/*
 * Базовый декоратор, который наследуется от абстрактного класса-компонента и имеет указатель на абстрактный компонент.
 * Таким образом он изменяет поведение хранимого компонента в наследуемых метода.
 */
class Decorator : public AbstractComponent
{
protected:
    AbstractComponent* component_;

public:
    Decorator(AbstractComponent* component);
    ~Decorator();

    std::string operation() const override;
    // ...

};
