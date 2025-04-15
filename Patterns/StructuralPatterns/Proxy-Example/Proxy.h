#pragma once

#include "RealSubject.h"

/*
 * Класс-заместитель для реального объекта
 */
class Proxy : public AbstractSubject
{
private:
    RealSubject* realSubject_;

public:
    Proxy(RealSubject* realSubject);
    ~Proxy();

    // Отнаследовали методы AbstractSubject
    void someAction() const override;
    // ...

private:
    /*
     * Дополнительные методы
     */
    void actionBefore() const;
    void actionAfter() const;

};
