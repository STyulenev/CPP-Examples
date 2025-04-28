#pragma once

#include <iostream>

#include "SomeClass.h"

/*
 * Примеры передачи аргументов в функцию:
 *
 * - Функция принимает копию и аргумент передаётся как копия.
 * - Функция принимает копию, но аргумент перемещается.
 * - Функция принимает ссылку, и аргумент передаётся как ссылка.
 * - Функция принимает временную ссылку и аргумент перемещается.
 *
 */

namespace Example1 {

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

void test1()
{
    std::cout << "test1()" << std::endl;

    SomeClass someClass;
    func1(someClass);
}

void test2()
{
    std::cout << std::endl << "test2()" << std::endl;

    SomeClass someClass;
    func1(std::move(someClass));
}

void test3()
{
    std::cout << std::endl << "test3()" << std::endl;

    SomeClass someClass;
    func2(someClass);
}

void test4()
{
    std::cout << std::endl << "test4()" << std::endl;

    SomeClass someClass;
    func3(std::move(someClass));
}

} // namespace Example1
