#pragma once

/*
 * Абстракция/Интерфейс для некоторого объекта
 */
class AbstractSubject
{
public:
    /*
     * Некоторые заготовки для полезных методов
     */
    virtual void someAction() const = 0;
    // ...

};
