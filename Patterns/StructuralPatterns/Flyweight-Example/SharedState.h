#pragma once

#include <iostream>
#include <string>

/*!
 * \brief Класс для хранения общих состояний
 */
class SharedState
{
public:
    std::string brand_;
    std::string model_;
    std::string color_;

    SharedState() = delete;
    SharedState(const std::string& brand, const std::string& model, const std::string& color);
    ~SharedState();

    friend std::ostream& operator<<(std::ostream& os, const SharedState& sharedState) {
        return os << "[ " << sharedState.brand_ << ", " << sharedState.model_ << ", " << sharedState.color_ << " ]";
    }
};
