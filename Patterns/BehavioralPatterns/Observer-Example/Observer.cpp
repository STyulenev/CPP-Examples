#include "Observer.h"

#include <iostream>

int Observer::staticNumber_ = 0;

Observer::Observer(Subject& subject) :
    subject_(subject)
{
    this->subject_.attach(this);
    std::cout << "Observer #" << ++Observer::staticNumber_ << " created" << std::endl;
    this->number_ = Observer::staticNumber_;
}

Observer::~Observer()
{
    std::cout << "Observer #" << this->number_ << " deleted" << std::endl;
}

void Observer::update(const std::string& messageFromSubject)
{
    messageFromSubject_ = messageFromSubject;
    printInfo();
}

void Observer::removeMeFromTheList()
{
    subject_.detach(this);
    std::cout << "Observer #" << number_ << "removed from the list." << std::endl;
}

void Observer::printInfo()
{
    std::cout << "Observer #" << this->number_ << ": a new message is available --> " << this->messageFromSubject_ << std::endl;
}
