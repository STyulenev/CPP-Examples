#pragma once

#include <iostream>

/*
 * Проблемы при использовании указателей
 *
 * Основная проблема у обычных указателей (pointers) заключается в управлении памятью. Указатели предоставляют мощный
 * инструмент для управления памятью, но они могут привести к ряду проблем, если не использовать их правильно.
 *
 * - Утечки памяти (Memory Leaks). Происходят, когда динамически выделенная память не освобождается. Если память не освобождается,
 * это приводит к тому, что она больше не доступна программе, что со временем может исчерпать доступную память.
 *
 * - Двойное освобождение памяти (Double Free). Происходит, когда одна и та же область памяти освобождается более одного раза.
 * Это приводит к неопределенному поведению и может вызвать сбой программы.
 *
 * - Использование освобожденной памяти (Dangling Pointer). Возникает, когда указатель продолжает использоваться после того,
 * как память, на которую он указывает, была освобождена. Это также приводит к неопределенному поведению.
 *
 * - Указатели на неинициализированную память (Uninitialized Pointer). Когда указатель используется до того, как ему присвоено
 * корректное значение. Это может привести к случайным ошибкам и сбоям программы.
 *
 * - Сложность в управлении памятью. Правильное управление жизненным циклом объектов, создание и освобождение памяти требуют
 * большого внимания и опыта. Ошибки в этих процессах могут быть труднонаходимыми и могут привести к нестабильной работе программы.
 */
namespace Example2 {

struct A
{
    A() { std::cout << "A::A()" << std::endl; }
    ~A() { std::cout << "A::~A()" << std::endl; }

    void print() { std::cout << "A::print()" << std::endl; }
};

/*
 * Утечка памяти. Не вызван delete после new.
 */
void test1()
{
    A* ptr = new A();

    // Утечка памяти
}

/*
 * Двойное освобождение памяти
 */
void test2()
{
    A* ptr = new A();

    delete ptr;
    delete ptr; // Второй вызов деструктора + аварийное завершение программы
}

/*
 * Использование освобожденной памяти
 */
void test3()
{
    A* ptr = new A();

    delete ptr;

    ptr->print(); // UB, может вызваться метод, а может произойти аварийное завершение и т.д.
}

/*
 * Указатели на неинициализированную память
 */
void test4()
{
    A* ptr;

    //if (ptr) {
        ptr->print(); // UB, может вызваться метод, а может произойти аварийное завершение и т.д.
    //}
}

/*
 * Сдвиг указателя
 */
void test5()
{
    A* ptr = new A();

    {
        ptr = ptr + 2; // Указатель передвинут на другой блок памяти
    }

    if (ptr) {
        ptr->print();
    }

    // delete ptr; // Аварийное завершение программы
}

/*
 * Потеря указателя
 */
void test6()
{
    A* ptr = new A();

    {
        ptr = new A(); // Указатель указывает на новый объект, утечка памяти (первый объект)
    }

    if (ptr) {
        ptr->print();
    }

    delete ptr; // Удаляется только второй объект
}

/*
 * Вызов неправильного delete
 */
void test7()
{
    A* ptr = new A();

    delete[] ptr; // Бесконечный вызов деструктора (пока не будет segmentation fault)
}

/*
 * Вызов неправильного delete
 */
void test8()
{
    A** arr = new A* [3];

    for (int i = 0; i < 3; i++) {
        arr[i] = new A[3]; // 3 x 3
    }

    delete[] arr; // Ошибка, утечка памяти + аварийное завершение программы

    // Ошибка
    /*for (int i = 0; i < 3; i++) {
        delete arr[i]; // Ошибка, утечка памяти +
    }*/

    // Правильно
    /*for (int i = 0; i < 3; i++) {
        delete[] arr[i];
    }*/
}

} // namespace Example2
