#include "Subject.h"

#include <iostream>

Subject::~Subject()
{
    std::cout << "Delete Subject." << std::endl;
}

void Subject::attach(IObserver* observer)
{
  list_observer_.push_back(observer);
}

void Subject::detach(IObserver* observer)
{
    list_observer_.remove(observer);
}

void Subject::notify()
{
    std::list<IObserver* >::iterator iterator = list_observer_.begin();

    observerCount();

    while (iterator != list_observer_.end()) {
        (*iterator)->update(message_);
        ++iterator;
    }
}

void Subject::createMessage(std::string message)
{
    this->message_ = message;
    notify();
}

void Subject::observerCount()
{
    std::cout << "There are " << list_observer_.size() << " observers in the list." << std::endl;
}

void Subject::someBusinessLogic() {
    this->message_ = "change message message";
    notify();
    std::cout << "... some logic ..." << std::endl;
}
