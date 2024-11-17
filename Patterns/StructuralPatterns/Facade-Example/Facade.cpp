#include "Facade.h"

Facade::Facade(SubSystem1* subsystem1, SubSystem2* subsystem2)
{
    this->subsystem1_ = subsystem1 ? : new SubSystem1();
    this->subsystem2_ = subsystem2 ? : new SubSystem2();
}

Facade::~Facade()
{
    delete subsystem1_;
    delete subsystem2_;
}

std::string Facade::operations()
{
    std::string result;

    result += this->subsystem1_->operation1() + "\n";
    result += this->subsystem1_->operation2() + "\n";
    result += this->subsystem2_->operation3() + "\n";
    result += this->subsystem2_->operation4() + "\n";

    return result;
}
