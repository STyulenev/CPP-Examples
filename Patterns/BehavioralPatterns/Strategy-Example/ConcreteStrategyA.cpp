#include "ConcreteStrategyA.h"

#include <numeric>

std::string ConcreteStrategyA::someAction(const std::vector<std::string>& data) const
{
    std::string result = std::accumulate(data.begin(), data.end(), std::string{});

    std::sort(std::begin(result), std::end(result));

    return result;
}
