#pragma once

#include "MediatorInterface.h"

/*!
 * \brief Базовый компонент
 */
class BaseComponent
{
protected:
    MediatorInterface* mediator_;

public:
    BaseComponent(MediatorInterface* mediator = nullptr);

    void setMediator(MediatorInterface* mediator);

};
