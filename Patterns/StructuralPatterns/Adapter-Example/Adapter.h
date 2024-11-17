#pragma once

#define MULTIPLE_INHERITANCE true // false

/*
 * Класс-адаптер включает в себя адаптируемый и целевой классы для предоставления клиенту
 * доработанной логики из них.
 */

#include "Adaptee.h"
#include "Target.h"

#if (MULTIPLE_INHERITANCE)

/*
 * Адаптер с единичным наследованием от Target и полем Adaptee
 */
class Adapter : public Target
{
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee);
    ~Adapter();

    std::string someAction() const override;

};

#else

/*
 * Адаптер с множественным наследованием
 */
class Adapter : public Target, public Adaptee
{
public:
    Adapter();
    ~Adapter();

    std::string someAction() const override;

};

#endif
