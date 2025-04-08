#pragma once

#include "Data.h"

/*
 * Интерфейс некоторого класса-объекта
 */
class IObject
{
public:
    virtual ~IObject();

    void someAction();

    // virtual method1() = 0;
    // virtual method2() = 0;
    // virtual ...

protected:
    Data* data = nullptr;

};

/*
 * Конкретная реализация класса-объекта
 */
class ConcreteObject1 : public IObject
{
public:
    ConcreteObject1();
    // ...

};

/*
 * Конкретная реализация класса-объекта
 */
class ConcreteObject2 : public IObject
{
public:
    ConcreteObject2();
    // ...

};

/*
 * Нулевая реализация класса-объекта
 */
class NullObject: public IObject
{
public:
    NullObject();
    // ...

};
