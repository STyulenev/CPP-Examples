#include "Proxy.h"

#include <iostream>

void Proxy::actionBefore() const
{
    std::cout << "Proxy: [ ";
}

void Proxy::actionAfter() const
{
    std::cout << " ]";
}

Proxy::Proxy(RealSubject* realSubject) :
    realSubject_(new RealSubject(*realSubject))
{

}

Proxy::~Proxy()
{
    delete realSubject_;
}

void Proxy::someAction() const
{
    this->actionBefore();
    // ...
    this->realSubject_->someAction();
    // ...
    this->actionAfter();
}
