#pragma once

#include <iostream>

/*
 * Интерфейс с методами
 */
class ISomeClass
{
public:
    virtual ~ISomeClass() {}

    virtual void print() const = 0;
    // ...

};

/*
 * Абстрактный класс с некоторыми данными
 */
class AbstractSomeClass
{
public:
    AbstractSomeClass() : field(5) {}
    AbstractSomeClass(const int field) : field(field) {}

    virtual ~AbstractSomeClass() {}

    void print() {
        std::cout << "AbstractSomeClass::field = " << this->field << std::endl;
    }

protected:
    int getField() const {
        return this->field;
    }

private:
    int field = 0;

};

/*
 * Конкретный класс 1
 */
class SomeClass1 : public ISomeClass, public AbstractSomeClass
{
public:
    SomeClass1() {}
    SomeClass1(const int field) : AbstractSomeClass(field) {}

    virtual ~SomeClass1() {}

    void print() const override {
        std::cout << "SomeClass1::field = " << AbstractSomeClass::getField() << std::endl;
    }

};

/*
 * Конкретный класс 2
 */
class SomeClass2 : public SomeClass1
{
public:
    SomeClass2() : SomeClass1(10) {}
    ~SomeClass2() {}

    void print() const override {
        std::cout << "SomeClass2::field = " << AbstractSomeClass::getField() << std::endl;
    }

};

