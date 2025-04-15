#include "RealSubject.h"

#include <iostream>

RealSubject::RealSubject()
{
    // ...
}

RealSubject::~RealSubject()
{
    // ...
}

void RealSubject::someAction() const
{
    std::cout << "RealSubject::someAction()";
}
