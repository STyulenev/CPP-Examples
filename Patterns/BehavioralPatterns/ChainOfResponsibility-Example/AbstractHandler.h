#pragma once

#include "HandlerInterface.h"

/*!
 * \brief Абстрактный класс, реализованный от интерфейса обработчика, обрабатывает цепочку обработчиков
 */
class AbstractHandler : public HandlerInterface
{
private:
    HandlerInterface* nextHandler_;

public:
    AbstractHandler();
    virtual ~AbstractHandler();

    /*!
     * \brief Метод для вставки следующего звена цепочки
     */
    HandlerInterface* next(HandlerInterface* handler) override;

    /*!
     * \brief Метод с полезной нагрузкой, который ищет по цепочке нужный someAction
     */
    std::string someAction(std::string data) override;

};
