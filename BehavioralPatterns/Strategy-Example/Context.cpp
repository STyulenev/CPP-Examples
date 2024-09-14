#include "Context.h"

#include <iostream>

Context::Context(StrategyInterface* strategy) :
    strategy_(strategy)
{
    // ...
}

Context::~Context()
{
    delete this->strategy_;
}

void Context::setStrategy(StrategyInterface* strategy)
{
    delete this->strategy_;
    this->strategy_ = strategy;
}

void Context::someBusinessLogic() const
{
    // ...
    std::cout << "Context: Sorting data using the strategy" << std::endl;
    std::string result = this->strategy_->someAction(std::vector<std::string>{"a", "e", "c", "b", "d"});
    std::cout << result << std::endl;
    // ...
}
