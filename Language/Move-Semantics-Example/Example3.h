#pragma once

#include <iostream>

#include "SomeClass.h"

/*
 * Пример forward
 *
 * Функция std::forward, как известно, применяется при идеальной передаче (perfect forwarding). Идеальная передача позволяет создавать
 * функции-обертки, передающие параметры без каких-либо изменений (lvalue передаются как lvalue, а rvalue – как rvalue) и тут
 * std::move нам не подходит, так как она безусловно приводит свой результат к rvalue.
 *
 * То есть std::forward для передачи lvalue-ссылки как lvalue-ссылку, а rvalue-ссылки как rvalue-ссылку
 *
 * Вывод: для перемещаемых объектов необходимо использовать std::move, а для идеальной передачи – std::forward.
 */

namespace Example3 {

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
 * Функция std::forward предназначена для реализации семантики перемещения. Она принимает lvalue-ссылку или rvalue-ссылку и возвращает
 * соответственную ссылку на этот объект. Одна из возможных реализаций std::forward выглядит так:
 */
template<typename T>
T&& _forward(T&& x)
{
    if (std::is_lvalue_reference<T>::value)
        return x;
    else
        return std::move(x); // cast to r-value
}

// С std::forward
void test1()
{
    std::cout << "\ntest3()\n\n";

    func1(std::forward<SomeClass>(SomeClass{}));

    std::cout << "\n\n";

    // func2(std::forward<SomeClass>(SomeClass{})); // Ошибка

    func3(std::forward<SomeClass>(SomeClass{}));
}

// Без std::forward
void test2()
{
    std::cout << "\ntest4()\n\n";

    func1(SomeClass{});

    std::cout << "\n\n";

    // func2(SomeClass{}); // Ошибка

    func3(SomeClass{});
}

void test3()
{
    std::cout << "\ntest5()\n\n";

    // func1(_forward<SomeClass>(SomeClass{})); // Ошибка
    // func2(std::forward<SomeClass>(SomeClass{})); // Ошибка

    func3(std::forward<SomeClass>(SomeClass{}));
}

} // namespace Example3
