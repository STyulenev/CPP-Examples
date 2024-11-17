#pragma once

#include <string>

/**
 * Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он
 * также объявляет метод для выполнения запроса.
 */
class HandlerInterface
{
public:
    virtual HandlerInterface* next(HandlerInterface* handler) = 0;
    virtual std::string someAction(std::string data) = 0;

};
