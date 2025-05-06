#pragma once

#include "IService.h"

#include <iostream>

/*
 * Конкретные сервисы
 */

class ConcreteService : public IService
{
public:
    void method() override {
        std::cout << "ConcreteService is working..." << std::endl;
    }

    // ...
};

// class ConcreteService2
// class OtherService
// ...
