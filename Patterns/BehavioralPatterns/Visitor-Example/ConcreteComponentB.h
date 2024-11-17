#pragma once

#include <string>

#include "ComponentInterface.h"

class VisitorInterface;

/*!
 * \brief Конкретный компонент с методами интерфейса и собственными
 */
class ConcreteComponentB : public ComponentInterface
{
public:
    void someAction(VisitorInterface* visitor) const override;

    std::string someActionConcreteComponentB() const;

};
