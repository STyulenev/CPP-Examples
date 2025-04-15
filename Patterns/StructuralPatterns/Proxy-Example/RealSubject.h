#pragma once

#include "AbstractSubject.h"

/*
 * Переопределённый класс реального объекта
 */
class RealSubject : public AbstractSubject
{
public:
    RealSubject();
    ~RealSubject();

    /*
     * Переопределённый метод someAction
     */
    void someAction() const override;

};
