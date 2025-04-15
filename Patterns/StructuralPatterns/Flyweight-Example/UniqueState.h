#pragma once

#include <iostream>
#include <string>

/*
 * Класс для хранения уникальных состояний
 */
class UniqueState
{
public:
    std::string owner_;
    std::string plates_;

    UniqueState() = delete;
    UniqueState(const std::string& owner, const std::string& plates);
    ~UniqueState();

    friend std::ostream &operator<<(std::ostream &os, const UniqueState& uniqueState) {
        return os << "[ " << uniqueState.owner_ << ", " << uniqueState.plates_ << " ]";
    }
};
