#pragma once

#include "Adaptee.h"
#include "Target.h"

/*
 *  Адаптер с единичным наследованием от Target и полем Adaptee
 */
class Adapter : public Target
{
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee);
    ~Adapter();

    std::string request() const override;

};

/*
 *  Адаптер с множественным наследованием
 */
/*class Adapter : public Target, public Adaptee
{
public:
    Adapter();
    ~Adapter();

    std::string request() const override;

};*/
