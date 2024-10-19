#include "Component.h"

Component::Component()
{
    // ...
}

Component::~Component()
{
    // ...
}

void Component::setParent(Component* parent)
{
    this->parent_ = parent;
}

Component* Component::getParent() const
{
    return this->parent_;
}

void Component::add(Component* component)
{

}

void Component::remove(Component* component)
{

}

bool Component::isComposite() const
{
    return false;
}
