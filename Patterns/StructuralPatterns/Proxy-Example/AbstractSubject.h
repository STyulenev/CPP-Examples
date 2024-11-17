#pragma once

/*!
 * \brief Абстракция/Интерфейс для некоторого объекта
 */
class AbstractSubject
{
public:
    /*!
     * \brief Чисто виртуальный метод someAction
     */
    virtual void someAction() const = 0;

};
