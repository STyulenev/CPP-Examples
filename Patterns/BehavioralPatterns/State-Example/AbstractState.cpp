#include "AbstractState.h"

AbstractState::AbstractState()
{
    // ...
}

AbstractState::~AbstractState()
{
    // ...
}

void AbstractState::setContext(Context* context)
{
    this->context_ = context;
}
