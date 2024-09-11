#pragma once

#include "RealSubject.h"

/*!
 * \brief Класс-заместитель для реального объекта
 */
class Proxy : public AbstractSubject
{
private:
    RealSubject* realSubject_;

public:
    Proxy(RealSubject* realSubject);
    ~Proxy();

    void someAction() const override;

private:
    void actionBefore() const;
    void actionAfter() const;

};
