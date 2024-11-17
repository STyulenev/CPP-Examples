#pragma once

#include <string>

class IObserver
{
public:
    virtual ~IObserver() {};
    virtual void update(const std::string& messageFromSubject) = 0;

};
