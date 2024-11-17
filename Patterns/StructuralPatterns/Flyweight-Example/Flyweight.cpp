#include "Flyweight.h"

Flyweight::Flyweight(const SharedState* sharedState) :
    sharedState_(new SharedState(*sharedState))
{
    // ...
}

Flyweight::Flyweight(const Flyweight& other) :
    sharedState_(new SharedState(*other.sharedState_))
{
    // ...
}

Flyweight::~Flyweight()
{
    delete sharedState_;
}

SharedState* Flyweight::sharedState() const
{
    return sharedState_;
}

void Flyweight::someAction(const UniqueState& uniqueState) const
{
    std::cout << "Flyweight: shared state (" << *sharedState_ << "), unique state (" << uniqueState << ") state." << std::endl;;
}
