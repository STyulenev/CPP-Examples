#pragma once

#include "SubSystem1.h"
#include "SubSystem2.h"

class Facade
{
protected:
    SubSystem1* subsystem1_;
    SubSystem2* subsystem2_;

public:
    Facade(SubSystem1* subsystem1 = nullptr, SubSystem2* subsystem2 = nullptr);
    ~Facade();

    std::string operations();

};
