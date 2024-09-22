#include "AbstractBase.h"

#include <iostream>

AbstractBase::AbstractBase(int parameter) :
    m_parameter(parameter)
{
    // Нельзя
    // method_1();
    // method_2();
    // ...

    std::cout << "AbstractBase::AbstractBase" << std::endl;
}

AbstractBase::~AbstractBase()
{
    std::cout << "AbstractBase::~AbstractBase" << std::endl;
}

void AbstractBase::initialization()
{
    std::cout << "AbstractBase::initialization" << std::endl;

    method_1();
    method_2();
    // ....
}
