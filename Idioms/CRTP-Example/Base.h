#pragma once

#include <iostream>

/*
 * Curiously Recurring Template Pattern (CRTP) - Странно рекурсивный шаблон.
 * Суть шаблона в следующем: некий класс наследуется от шаблонного класса класса и наследник используется
 * как параметр шаблона своего базового класса. CRTP позволяет обойтись без виртуальных функций, что позволяет
 * получить выигрышь во времени.
 *
 * - При использовании наследования от AbstractBase с чисто виртуальной функцией 'virtual void interface() = 0;'
 * будет происходить переопределение и вызов метода 'void interface() ovveride;' в наследниках ConcreteClass1 и ConcreteClass1:
 *
 * class AbstractBase
 * {
 * public:
 *     virtual void interface() = 0;
 *
 *     // ...
 * };
 *
 * class ConcreteClass1 : public AbstractBase
 * {
 * public:
 *     void interface() override {
 *         std::cout<< " --> ConcreteClass1::interface()" << std::endl;
 *         // ...
 *     }
 *
 *     // ...
 * };
 *
 * - При CRTP будет вызван метод 'void interface();' только из AbstractBase, который при приведении может вызывать любой метод
 * наследника.
 *
*/

template <typename Type>
class AbstractBase
{
public:
    AbstractBase() {
        count++;
        std::cout<< "count = " << count << std::endl;
    }

    ~AbstractBase() {
        count--;
        std::cout<< "count = " << count << std::endl;
    }

    // Вызов метода наследника
    void interface() {
        static_cast<Type*>(this)->implementation();
    };

private:
    static int count; // Свой счётчик для каждого типа

};

template <typename Type>
int AbstractBase<Type>::count = 0;

/*
 * Необязательный интерфейс, чтобы не ошибиться в сигнатуре метода implementation.
 */
class IBase
{
public:
    virtual void implementation() = 0;

};

