#pragma once

#include "IService.h"

#include <iostream>

/*
 * Класс-секретарь, который управляет доступом к сервису
 */
class Servant
{
private:
    IService* service;

public:
    Servant(IService* srv) : service(srv) {}

    // Фасад для полезного метода method()
    void doMethod() {
        std::cout << "Servant is preparing to work..." << std::endl;

        if (service) {
            service->method();
        } else {
            // ...
        }
    }

    // ...

};
