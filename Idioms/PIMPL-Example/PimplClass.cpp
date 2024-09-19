#include "PimplClass.h"

namespace PimplNamespase {

PimplClass::PimplClass(const std::string& data) :
    m_data(data)
{
    // ...
}

PimplClass::~PimplClass()
{
    // ...
}

const std::string& PimplClass::getData() const
{
    return m_data;
}

} // namespace PimplNamespase
