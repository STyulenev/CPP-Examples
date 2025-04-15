#include "Facade.h"

Facade::Facade(SubSystem1* subsystem1, SubSystem2* subsystem2)
{
    // Создаём, если пришли nullptr
    //this->subsystem1_ = subsystem1 ? : new SubSystem1();
    //this->subsystem2_ = subsystem2 ? : new SubSystem2();

    // Без проверки
    this->subsystem1_ = subsystem1;
    this->subsystem2_ = subsystem2;
}

Facade::~Facade()
{
    if (subsystem1_)
        delete subsystem1_;

    if (subsystem2_)
        delete subsystem2_;
}

std::string Facade::operations()
{
    std::string result;

    if (subsystem1_) {
        result += this->subsystem1_->operation1() + "\n";
        result += this->subsystem1_->operation2() + "\n";
    }

    if (subsystem2_) {
        result += this->subsystem2_->operation3() + "\n";
        result += this->subsystem2_->operation4() + "\n";
    }

    return result;
}
