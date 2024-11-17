#include "Composite.h"

Composite::Composite()
{
    // ...
}

Composite::~Composite()
{
    // ...
}

void Composite::add(Component* component)
{
    this->children_.push_back(component);
    component->setParent(this);
}

void Composite::remove(Component* component)
{
    children_.remove(component);
    component->setParent(nullptr);
}

bool Composite::isComposite() const
{
    return true;
}

std::string Composite::someAction() const
{
    std::string result;

    for (const Component* children : children_) {
        if (children == children_.back()) {
            result += children->someAction();
        } else {
            result += children->someAction() + "+";
        }
    }

    return "Branch(" + result + ")";
}
