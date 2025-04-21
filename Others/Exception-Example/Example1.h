#pragma once

#include <iostream>

/*
 * Последовательность обработки исключений
 */

namespace Example1 {

class A
{
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    virtual void what() const noexcept {
        std::cout << "A::what()" << std::endl;
    }

};

class B : public A
{
public:
    B() {
        std::cout << "B()" << std::endl;
    }

    virtual void what() const noexcept override {
        std::cout << "B::what()" << std::endl;
    }

};

class C : public B
{
public:
    C() {
        std::cout << "C()" << std::endl;
    }

    virtual void what() const noexcept override {
        std::cout << "C::what()" << std::endl;
    }

};

void test1()
{
    /*
     * A()
     * A::what()
     */

    try {
        throw A();
    }
    catch (const C& c) { // от наследников
        c.what();
    }
    catch (const B& b) {
        b.what();
    }
    // ...
    catch (const A& a) { // к абстракции
        a.what();
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

void test2()
{
    /*
     * A()
     * B()
     * B::what()
     */

    try {
        throw B();
    }
    catch (const C& c) { // от наследников
        c.what();
    }
    catch (const B& b) {
        b.what();
    }
    // ...
    catch (const A& a) { // к абстракции
        a.what();
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

void test3()
{
    /*
     * A()
     * B()
     * C()
     * C::what()
     */

    try {
        throw C();
    }
    catch (const C& c) { // от наследников
        c.what();
    }
    catch (const B& b) {
        b.what();
    }
    // ...
    catch (const A& a) { // к абстракции
        a.what();
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

void test4()
{
    /*
     * A()
     * B()
     * C()
     * C::what()
     */

    try {
        throw C();
    }
    catch (const A& a) {
        a.what(); // С virtual функцией будет C::what(), без A::what()
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

} // namespace Example1
