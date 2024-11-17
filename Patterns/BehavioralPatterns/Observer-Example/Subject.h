#pragma once

#include <list>

#include "IObserver.h"
#include "ISubject.h"

/*!
 * \brief Класс-издатель
 */
class Subject : public ISubject
{
public:
    virtual ~Subject();

    /*!
     * \brief Подключить класс-наблюдатель
     */
    void attach(IObserver* observer) override;
    /*!
     * \brief Отключить класс-наблюдатель
     */
    void detach(IObserver* observer) override;
    /*!
     * \brief Уведомить классы-наблюдатель
     */
    void notify() override;

    void createMessage(std::string message = "Empty");
    void observerCount();

    /**
  *  Обычно логика подписки – только часть того, что делает Издатель. Издатели
  *  часто содержат некоторую важную бизнес-логику, которая запускает метод
  *  уведомления всякий раз, когда должно произойти что-то важное (или после
  *  этого).
  */
    void someBusinessLogic();

private:
    std::list<IObserver* > list_observer_;
    std::string message_;
};
