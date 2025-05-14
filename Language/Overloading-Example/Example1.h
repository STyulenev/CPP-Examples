#pragma once

#include <iostream>

/*
 * Примеры всевозможных перегрузок метода класса:
 *
 * - Для rvalue и lvalue объектов;
 * - Для const и не const объектов;
 * - Для volatile и не volatile объектов;
 * - Для const volatile и не const volatile объектов;
 * - Для rvalue и lvalue объектов + типизация шаблона;
 * - Для const и не const объектов + типизация шаблона;
 * - Для volatile и не volatile объектов + типизация шаблона;
 * - Для const volatile и не const volatile объектов + типизация шаблона.
 * - Различное количество аргументов.
 * - Различные типы аргументов.
 * - Различные уровни указателя
 * - Различная передача [ссылка, указатель, ссылка на эказатель, rvalue/lvalue, +const, +volatile, ... ]
 *
 */

namespace Example1 {

struct SomeClass {

    static const SomeClass createC() {
        return SomeClass();
    }

    static volatile SomeClass createV() {
        return SomeClass();
    }

    static const volatile SomeClass createCV() {
        return SomeClass();
    }

    // void foo() {} // Ошибка, уже есть "void foo() &"
    // void foo(int n = 0) & {} // Ошибка, уже есть "void foo() &"

    // void foo() & noexcept  // Ошибка, noexcept не перегружает функцию/метод
    // static void foo() & {} // Ошибка, static не перегружает функцию/метод
    // inline void foo() & {} // Ошибка, inline не перегружает функцию/метод

    // Перегрузка метода без параметров

    void foo() & {
        std::cout << "void foo() &" << std::endl;
    }

    void foo() && {
        std::cout << "void foo() &&" << std::endl;
    }

    void foo() const & {
        std::cout << "void foo() const &" << std::endl;
    }

    void foo() const && {
        std::cout << "void foo() const &&" << std::endl;
    }

    void foo() volatile & {
        std::cout << "void foo() volatile &" << std::endl;
    }

    void foo() volatile && {
        std::cout << "void foo() volatile &&" << std::endl;
    }

    void foo() const volatile & {
        std::cout << "void foo() const volatile &" << std::endl;
    }

    void foo() const volatile && {
        std::cout << "void foo() const volatile &&" << std::endl;
    }

    // Перегрузка метода с параметром

    void foo(int x) {
        std::cout << "void foo(int x)" << std::endl;
    }

    // void foo(const int x) {}          // Ошибка, это равнозначно void foo(int x) т.к. const удаляется из-за передачи по значению
    // void foo(const volatile int x) {} // Ошибка, это равнозначно т.к. const volatile удаляется из-за передачи по значению
    // long long int foo(int x) {}       // Ошибка, нельзя перегружать по возвращаемому значению

    void foo(int* x) {
        std::cout << "void foo(int* x)" << std::endl;
    }

    void foo(int** x) {
        std::cout << "void foo(int** x)" << std::endl;
    }

    void foo(int*& x) {
        std::cout << "void foo(int* x)" << std::endl;
    }

    void foo(int& x) {
        std::cout << "void foo(int& x)" << std::endl;
    }

    void foo(int&& x) {
        std::cout << "void foo(int&& x)" << std::endl;
    }

    void foo(const int& x) {
        std::cout << "void foo(const int& x)" << std::endl;
    }

    void foo(const int&& x) {
        std::cout << "void foo(const int&& x)" << std::endl;
    }

    void foo(const volatile int& x) {
        std::cout << "void foo(const volatile int& x)" << std::endl;
    }

    void foo(const volatile int&& x) {
        std::cout << "void foo(const volatile int&& x)" << std::endl;
    }

    // Ко всем вышеперечисленным методам можно добавить & / && / const / volatile, как в примерах выше
    // Количестов аргументов может быть увеличено
    // Количество уровеней указателя может быть любым
    // Может быть ссылка на указатель

    // Перегрузка метода шаблоном

    template<typename T>
    void foo() & {
        std::cout << "void foo<" << typeid(T).name() << ">() &" << std::endl;
    }

    template<typename T>
    void foo() && {
        std::cout << "void foo<" << typeid(T).name() << ">() &&" << std::endl;
    }

    template<typename T>
    void foo() const & {
        std::cout << "void foo<" << typeid(T).name() << ">() const &" << std::endl;
    }

    template<typename T>
    void foo() const && {
        std::cout << "void foo<" << typeid(T).name() << ">() const &&" << std::endl;
    }

    template<typename T>
    void foo() volatile & {
        std::cout << "void foo<" << typeid(T).name() << ">() volatile &" << std::endl;
    }

    template<typename T>
    void foo() volatile && {
        std::cout << "void foo<" << typeid(T).name() << ">() volatile &&" << std::endl;
    }

    template<typename T>
    void foo() const volatile & {
        std::cout << "void foo<" << typeid(T).name() << ">() const volatile &" << std::endl;
    }

    template<typename T>
    void foo() const volatile && {
        std::cout << "void foo<" << typeid(T).name() << ">() const volatile &&" << std::endl;
    }

};

void test()
{
    {
        SomeClass lvalue;
        lvalue.foo();      // void foo() &
        SomeClass{}.foo(); // void foo() &&
    }

    std::cout << std::endl;

    {
        const SomeClass lvalue;
        lvalue.foo();               // void foo() const &
        SomeClass::createC().foo(); // void foo() const &&
    }

    std::cout << std::endl;

    {
        volatile SomeClass lvalue;
        lvalue.foo();               // void foo() volatile &
        SomeClass::createV().foo(); // void foo() volatile &&
    }

    std::cout << std::endl;

    {
        const volatile SomeClass lvalue;
        lvalue.foo();                // void foo() const volatile &
        SomeClass::createCV().foo(); // void foo() const volatile &&
    }

    std::cout << std::endl;

    {
        SomeClass* value = new SomeClass();
        value->foo(); // void foo() &
        delete value;
    }

    std::cout << std::endl;

    {
        SomeClass lvalue;
        lvalue.foo<int>();      // void foo<i>() &
        SomeClass{}.foo<int>(); // void foo<i>() &&
    }

    std::cout << std::endl;

    {
        const SomeClass lvalue;
        lvalue.foo<int>();               // void foo<i>() const &
        SomeClass::createC().foo<int>(); // void foo<i>() const &&
    }

    std::cout << std::endl;

    {
        volatile SomeClass lvalue;
        lvalue.foo<int>();               // void foo<i>() volatile &
        SomeClass::createV().foo<int>(); // void foo<i>() volatile &&
    }

    std::cout << std::endl;

    {
        const volatile SomeClass lvalue;
        lvalue.foo<int>();                // void foo<i>() const volatile &
        SomeClass::createCV().foo<int>(); // void foo<i>() const volatile &&
    }

    std::cout << std::endl;

    {
        SomeClass* value = new SomeClass();
        value->foo<int>(); // void foo<i>() &
        delete value;
    }
}

} // namespace Example1
