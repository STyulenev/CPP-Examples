#include "Director.h"

Director::Director() :
    builder()
{

}

Director::~Director()
{
    if (builder) {
        delete builder;
    }
}

void Director::set(AbstractBuilder* builder)
{
    if (this->builder) {
        delete this->builder;
    }

    this->builder = builder;
}

Product Director::get()
{
    return builder->get();
}

void Director::construct()
{
    builder->buildPartA();
    builder->buildPartB();
    builder->buildPartC();
    // ...
}
