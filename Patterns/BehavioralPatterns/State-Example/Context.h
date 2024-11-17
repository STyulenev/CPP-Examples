#pragma once

#include "AbstractState.h"

/*!
 * \brief Класс-контекст выполняет полезную нагрузку и в процессе меняет состояния
 */
class Context
{
    /**
   * @var State Ссылка на текущее состояние Контекста.
   */
private:
    /*!
     * \brief Текущее состояние
     */
    AbstractState* state_;

public:
    Context(AbstractState* state);
    ~Context();

    /*!
     * \brief Смена состояния
     */
    void transitionTo(AbstractState *state);

    /*!
     * \brief Методы с полезной нагрузкой, которые работают с состояниями
     */
    void request1();
    void request2();

};
