#pragma once

#include <list>

#include "Component.h"

/*
 * Класс-контейнер для компонентов. Данный класс может включать в себя целые ответвления и одиночные листы
 */
class Composite : public Component
{
protected:
    std::list<Component*> children_;

public:
    Composite();
    ~Composite();

    void add(Component* component) override;
    void remove(Component* component) override;
    bool isComposite() const override;
    std::string someAction() const override;

};
