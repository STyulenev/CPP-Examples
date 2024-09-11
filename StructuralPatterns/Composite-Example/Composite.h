#pragma once

#include <list>

#include "Component.h"

/*!
 * \brief Класс-контейнер для компонентов
 */
class Composite : public Component
{
protected:
    std::list<Component*> children_;

public:
    void add(Component* component) override;
    void remove(Component* component) override;

    bool IsComposite() const override;

    std::string someAction() const override;
};
