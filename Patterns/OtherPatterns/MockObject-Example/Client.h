#pragma once

#include "IService.h"

/*
 * Использование сервиса в клиентском классе
 */
class Client
{
private:
    IService* service;

public:
    Client(IService* svc) : service(svc) {
        // ...
    }

    ~Client() {
        // ...
    }

    int execute(int value) {
        return service->performAction(value);
    }
};
