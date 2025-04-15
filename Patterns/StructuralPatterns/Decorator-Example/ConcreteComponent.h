#pragma once

#include "AbstractComponent.h"

/*
 * Конкретный компонент с поведением по умолчанию.
 */
class ConcreteComponent : public AbstractComponent
{
public:
    ConcreteComponent();
    ~ConcreteComponent();

    std::string operation() const override;

};
