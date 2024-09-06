#pragma once

#include <string>

class Target
{
public:
    Target();
    virtual ~Target();

    virtual std::string request() const;

};
