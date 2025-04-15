#include "SharedState.h"

SharedState::SharedState(const std::string &brand, const std::string &model, const std::string &color) :
    brand_(brand),
    model_(model),
    color_(color)
{
    // ...
}

SharedState::~SharedState()
{
    // ...
}
