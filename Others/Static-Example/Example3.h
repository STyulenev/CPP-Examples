#pragma once

namespace Example3 {

class SomeClass
{
public:
    static void print();
    static void num1();
    static void num2();

private:
    static const int _num1 = 0;
    static int _num2;

};


static void test1()
{
    SomeClass::print();
}

static void test2()
{
    SomeClass::num1();
}

static void test3()
{
    SomeClass::num2();
}

void test4();

} // namespace Example3
