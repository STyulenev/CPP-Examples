#pragma once

#include "MementoInterface.h"

/*!
 * \brief Конкретный снимок
 */
class ConcreteMemento : public MementoInterface
{
private:
    std::string state_;
    std::string date_;

public:
    ConcreteMemento(std::string state);

    std::string getName() const override;
    std::string state() const override;
    std::string date() const override;

};
