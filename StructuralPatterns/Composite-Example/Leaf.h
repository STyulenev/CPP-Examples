#pragma once

#include "Component.h"

/*!
 * \brief Класс Leaf рассчитан только для выполнения некоторых действий и не должен иметь подкомпоненты
 */
class Leaf : public Component
{
public:
    std::string someAction() const override;

};
