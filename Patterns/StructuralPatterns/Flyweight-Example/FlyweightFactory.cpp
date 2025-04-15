#include "FlyweightFactory.h"

FlyweightFactory::FlyweightFactory(std::initializer_list<SharedState> share_states)
{
    // Заполняем общие данные
    for (const SharedState& sharedState : share_states) {
        this->flyweights_.insert(std::make_pair<std::string, Flyweight>(this->getHash(sharedState), Flyweight(&sharedState)));
    }
}

FlyweightFactory::~FlyweightFactory()
{
    // ...
}

Flyweight FlyweightFactory::getFlyweight(const SharedState& shared_state)
{
    std::string key = this->getHash(shared_state);

    if (this->flyweights_.find(key) == this->flyweights_.end()) {
        std::cout << "FlyweightFactory: There is not a flyweight, creating..." << std::endl;
        this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
    } else {
        std::cout << "FlyweightFactory: Reusing existing flyweight." << std::endl;
    }

    return this->flyweights_.at(key);
}

void FlyweightFactory::getListFlyweights() const
{
    size_t count = this->flyweights_.size();
    std::cout << "FlyweightFactory have: " << count << " flyweights:" << std::endl;

    for (const std::pair<std::string, Flyweight>& pair : this->flyweights_) {
        std::cout << "\t" << pair.first << std::endl;
    }
}

std::string FlyweightFactory::getHash(const SharedState& sharedState) const
{
    return sharedState.brand_ + " " + sharedState.model_ + " " + sharedState.color_;
}

