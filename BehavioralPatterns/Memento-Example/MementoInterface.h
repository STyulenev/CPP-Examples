#pragma once

#include <string>

/*!
 * \brief Интерфейс снимка
 */
class MementoInterface
{
public:
    virtual std::string getName() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;

};
