#pragma once

#include "StrategyInterface.h"

/*!
 * \brief Конкретная стратегия с кокретной реализацией someAction
 */
class ConcreteStrategyB : public StrategyInterface
{
public:
    std::string someAction(const std::vector<std::string>& data) const override;

};
