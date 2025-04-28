#pragma once

#include <iostream>

#include "SomeClass.h"

/*
 * Пример move
 *
 * В функцию std::move может быть передана как lvalue-ссылка, так и rvalue-ссылка, а результатом должна являться rvalue-ссылка.
 * Поэтому для обозначения возвращаемого типа сначала можно использовать трейт std::remove_reference_t, который упрощает шаблонный тип
 * T до обычного нессылочного типа, а затем явно добавляем '&&'.
 *
 * То есть std::move для передачи lvalue / rvalue-ссылки в rvalue-ссылку.
 *
 * Вывод: для перемещаемых объектов необходимо использовать std::move, а для идеальной передачи – std::forward.
 */

namespace Example2 {

void func1([[maybe_unused]] SomeClass someClass)
{
    std::cout << "func #1" << std::endl;
}

void func2([[maybe_unused]] SomeClass& someClass)
{
    std::cout << "func #2" << std::endl;
}

void func3([[maybe_unused]] SomeClass&& someClass)
{
    std::cout << "func #3" << std::endl;
}

/*
 * Функция std::move предназначена для реализации семантики перемещения. Она принимает forwarding-ссылку на объект и возвращает rvalue-ссылку
 * на этот объект. Одна из возможных реализаций std::move выглядит так:
 */
template<typename T>
std::remove_reference_t<T>&& _move(T&& x)
{
    return static_cast<std::remove_reference_t<T>&&>(x);
}

void test1()
{
    std::cout << "test1()\n\n";

    SomeClass someClass;
    func3(_move(someClass));
}

void test2()
{
    std::cout << "\ntest2()\n\n";

    SomeClass someClass;
    func1(_move(someClass));
}

} // namespace Example2
