#pragma once

#include "AbstractSubject.h"

/*!
 * \brief Переопределённый класс реального объекта
 */
class RealSubject : public AbstractSubject
{
public:
    /*!
     * \brief Переопределённый метод someAction
     */
    void someAction() const override;

};
