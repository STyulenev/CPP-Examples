#pragma once

#include "StrategyInterface.h"

/*!
 * \brief Класс-контекст выполняющий бизнес-логику с заданной стратегией
 */
class Context
{
private:
    /*!
     * \brief Текущая стратегия
     */
    StrategyInterface* strategy_;

public:
    Context() = delete;
    Context(StrategyInterface* strategy = nullptr);
    ~Context();

    /*!
     * \brief Сменить текущую стратегию
     */
    void setStrategy(StrategyInterface *strategy);

    /*!
     * \brief Метод для выполнения бизнес-логики с заданой стратегией
     */
    void someBusinessLogic() const;
};
