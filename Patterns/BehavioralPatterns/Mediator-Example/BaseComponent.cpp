#include "BaseComponent.h"

BaseComponent::BaseComponent(MediatorInterface* mediator) :
    mediator_(mediator)
{
    // ...
}

void BaseComponent::setMediator(MediatorInterface* mediator)
{
    this->mediator_ = mediator;
}
