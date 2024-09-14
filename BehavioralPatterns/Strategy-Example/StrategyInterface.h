#pragma once

#include <string>
#include <vector>

/*!
 * \brief Интерфейс Стратегии объявляет методы, для реалзации в классах-наследниках (конкретных стратегиях)
 */
class StrategyInterface
{
public:
    virtual ~StrategyInterface() {}

    virtual std::string someAction(const std::vector<std::string>& data) const = 0;

};
