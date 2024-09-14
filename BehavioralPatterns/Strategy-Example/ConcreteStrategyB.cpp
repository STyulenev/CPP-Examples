#include "ConcreteStrategyB.h"

#include <numeric>

std::string ConcreteStrategyB::someAction(const std::vector<std::string>& data) const
{
    std::string result = std::accumulate(data.begin(), data.end(), std::string{});

    std::sort(std::begin(result), std::end(result));

    for (int i = 0; i < result.size() / 2; i++) {
        std::swap(result[i], result[result.size() - i - 1]);
    }

    return result;
}
