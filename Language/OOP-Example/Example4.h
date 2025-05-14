#pragma once

#include <iostream>

/*
 * Пример ромбовидного виртуального наследования
 */
namespace Example4 {

class Base
{
public:
    explicit Base(int a) : a(a) {
        std::cout << "Base::Base(int a)" << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base::~Base()" << std::endl;
    }

    int getA() const{
        return a;
    }

private:
    int a;
};

class DerivedA : virtual public Base
{
public:
    DerivedA() = delete;

    explicit DerivedA(int a) : Base(a) {
        std::cout << "DerivedA::DerivedA()" << std::endl;
    }

    virtual ~DerivedA() {
        std::cout << "DerivedA::~DerivedA()" << std::endl;
    }
};

class DerivedB : virtual public Base
{
public:
    DerivedB() = delete;

    explicit DerivedB(int a) : Base(a) {
        std::cout << "DerivedB::DerivedB()" << std::endl;
    }

    virtual ~DerivedB() {
        std::cout << "DerivedB::~DerivedB()" << std::endl;
    }
};

class DerivedFinal final : public DerivedA, public DerivedB
{
public:
    DerivedFinal() = delete;

    DerivedFinal(int a, int b, int c) : DerivedA(a), DerivedB(b), Base(c) {
        std::cout << "DerivedFinalA::DerivedFinalA()" << std::endl;
    }

    ~DerivedFinal() {
        std::cout << "DerivedFinalA::~DerivedFinalA()" << std::endl;
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    DerivedFinal* a = new DerivedFinal(3, 4, 5);

    std::cout << "(DerivedA*) a = " << dynamic_cast<DerivedA*>(a)->getA() << std::endl;
    std::cout << "(DerivedB*) a = " << dynamic_cast<DerivedB*>(a)->getA() << std::endl;
    std::cout << "(Base*) a = "     << dynamic_cast<Base*>(a)->getA()     << std::endl;

    delete a;
}

} // namespace Example4
