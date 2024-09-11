#pragma once

#include <iostream>
#include <string>

/*!
 * \brief Класс для хранения уникальных состояний
 */
class UniqueState
{
public:
    std::string owner_;
    std::string plates_;

    UniqueState(const std::string& owner, const std::string& plates);

    friend std::ostream &operator<<(std::ostream &os, const UniqueState& uniqueState) {
        return os << "[ " << uniqueState.owner_ << ", " << uniqueState.plates_ << " ]";
    }
};
