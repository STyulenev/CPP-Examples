#pragma once

#include "Component.h"

/*
 * Класс Leaf (лист, по аналогии с деревом) рассчитан только для выполнения некоторых действий и
 * не должен иметь подкомпоненты
 */
class Leaf : public Component
{
public:
    Leaf();
    ~Leaf();

    std::string someAction() const override;

};
