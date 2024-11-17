#pragma once

#include <string>

class BaseComponent;

/*!
 * \brief Интерфейс посредника
 */
class MediatorInterface
{
public:
    virtual void notify(BaseComponent* sender, std::string event) const = 0;

};
