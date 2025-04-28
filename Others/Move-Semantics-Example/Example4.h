#pragma once

#include <iostream>

#include "SomeClass.h"

/*
 * Ещё немного примеров move-семантики
 */

namespace Example4 {

void func([[maybe_unused]]const SomeClass& someClass)
{
    std::cout << "func #1" << std::endl;
}

void func([[maybe_unused]] SomeClass& someClass)
{
    std::cout << "func #2" << std::endl;
}

void func([[maybe_unused]] SomeClass&& someClass)
{
    std::cout << "func #3" << std::endl;
}

//void func([[maybe_unused]] SomeClass someClass) {} // Ошибка func is ambiguous ...

/*
 * Пример обёртки для идеальной передачи
 */
template<class T>
void wrapper(T&& arg)
{
    // arg is always lvalue
    func(std::forward<T>(arg)); // Forward as lvalue or as rvalue, depending on T
}

void test1()
{
    std::cout << "\ntest1()\n\n";

    SomeClass someClass;

    wrapper(someClass); // func #2
}

void test2()
{
    std::cout << "\ntest2()\n\n";

    wrapper(SomeClass{}); // func #3
}

void test3()
{
    std::cout << "\ntest3()\n\n";

    const SomeClass someClass;

    wrapper(someClass); // func #1
}

void test4()
{
    std::cout << "\ntest4()\n\n";

    auto lambda1 = []([[maybe_unused]] SomeClass someClass) -> void {
        std::cout << "lambda #1" << std::endl;
    };

    auto lambda2 = []([[maybe_unused]] SomeClass&& someClass) -> void {
        std::cout << "lambda #2" << std::endl;
    };

    auto lambda3 = []([[maybe_unused]] SomeClass& someClass) -> void {
        std::cout << "lambda #3" << std::endl;
    };

    SomeClass someClass;

    lambda1(std::forward<SomeClass>(someClass));
    lambda1(std::forward<SomeClass&>(someClass));
    lambda1(std::forward<SomeClass&&>(someClass));
    lambda1(std::forward<SomeClass>(SomeClass{}));

    lambda2(std::forward<SomeClass>(someClass));
    lambda2(std::forward<SomeClass>(SomeClass{}));
    // lambda2(std::forward<SomeClass&>(someClass)); // Ошибка
    lambda2(std::forward<SomeClass&&>(SomeClass{}));

    // lambda3(std::forward<SomeClass>(someClass)); // Ошибка
    lambda3(std::forward<SomeClass&>(someClass));
    // lambda3(std::forward<SomeClass&&>(SomeClass{})); // Ошибка
    // lambda3(std::forward<SomeClass&&>(someClass)); // Ошибка
}

} // namespace Example4
