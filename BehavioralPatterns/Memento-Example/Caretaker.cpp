#include "Caretaker.h"

#include <iostream>

#include "Originator.h"

Caretaker::Caretaker(Originator* originator) :
    originator_(originator)
{
    this->originator_ = originator;
}

void Caretaker::backup()
{
    std::cout << "Caretaker: saving..." << std::endl;

    this->mementos_.push_back(this->originator_->save());
}

void Caretaker::undo()
{
    if (!this->mementos_.size()) {
        return;
    }

    MementoInterface* memento = this->mementos_.back();
    this->mementos_.pop_back();

    std::cout << "Caretaker: restoring state to: " << memento->getName() << std::endl;

    try {
        this->originator_->restore(memento);
    } catch (...) {
        this->undo();
    }
}

void Caretaker::history() const
{
    std::cout << "Caretaker: show history:" << std::endl;

    for (MementoInterface *memento : this->mementos_) {
        std::cout << "  -> " << memento->getName() << std::endl;
    }
}
