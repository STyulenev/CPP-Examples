#include "ConcreteMediator.h"

#include <iostream>

ConcreteMediator::ConcreteMediator(Component1* c1, Component2* c2) :
    component1_(c1),
    component2_(c2)
{
    this->component1_->setMediator(this);
    this->component2_->setMediator(this);
}

void ConcreteMediator::notify(BaseComponent* sender, std::string event) const
{
    if (event == "A") {
        std::cout << "Mediator reacts on A and triggers following operations:" << std::endl;
        this->component2_->doC();
    }

    if (event == "D") {
        std::cout << "Mediator reacts on D and triggers following operations:" << std::endl;
        this->component1_->doB();
        this->component2_->doC();
    }
}
