#include "Adapter.h"

Adapter::Adapter(Adaptee* adaptee) :
    adaptee_(adaptee)
{

}

Adapter::~Adapter()
{

}

std::string Adapter::request() const
{
    std::string data = this->adaptee_->specificRequest();

    return data + " with processing";
}

/*Adapter::Adapter()
{

}

Adapter::~Adapter()
{

}

std::string Adapter::request() const
{
    std::string data = this->adaptee_->specificRequest();

    return data + " with processing";
}*/
