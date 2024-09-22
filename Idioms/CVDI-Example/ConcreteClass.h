#pragma once

#include "AbstractBase.h"

#include <memory>

/*
 * Конкретная реализация
 */
class ConcreteClass : public AbstractBase
{
public:
    ConcreteClass(int parameter);
    ~ConcreteClass();

    virtual void method_1() const override;
    virtual void method_2() const override;

private:
    // ...

};

/*
 * Шаблонный метод, который используется вместо конструктора для создания объекта и вызова виртуальных методов
 */
template<class ClassType, class Parameter>
std::unique_ptr<AbstractBase> factory(Parameter parameter)
{
    std::unique_ptr<AbstractBase> uptr(new ClassType(parameter));
    uptr->initialization();
    return uptr;
}
