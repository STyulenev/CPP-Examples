#pragma once

#include "Component1.h"
#include "Component2.h"

/**
*  Конкретные Посредники реализуют совместное поведение, координируя отдельные
*  компоненты.
*/
class ConcreteMediator : public MediatorInterface
{
private:
    Component1* component1_;
    Component2* component2_;

public:
    ConcreteMediator(Component1* c1, Component2* c2);

    void notify(BaseComponent* sender, std::string event) const override;

};
