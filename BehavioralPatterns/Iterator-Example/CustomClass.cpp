#include "CustomClass.h"

CustomClass::CustomClass(int data) :
    m_data_(data)
{
    // ...
}

CustomClass::~CustomClass()
{
    // ...
}

void CustomClass::setData(int data)
{
    m_data_ = data;
}

int CustomClass::getData() const
{
    return m_data_;
}
