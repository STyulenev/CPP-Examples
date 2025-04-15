#pragma once

#include <string>

/*
 * Абстрактный компонент  определяет поведение, которое будет изменено декораторами.
 */
class AbstractComponent
{
public:
    virtual ~AbstractComponent() {}

    virtual std::string operation() const = 0;
    // ...

};
