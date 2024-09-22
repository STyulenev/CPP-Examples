#pragma once

/*
 * Некоторый интерфейс
 */
class IFirst
{
public:
    virtual ~IFirst() {}

    virtual void method_1() const = 0;
    //...

};
