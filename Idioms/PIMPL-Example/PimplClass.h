#pragma once

#include <string>

namespace PimplNamespase {

class PimplClass
{
public:
    PimplClass(const std::string& data);
    ~PimplClass();

    const std::string& getData() const;

private:
    std::string m_data;

};

} // namespace PimplNamespase
