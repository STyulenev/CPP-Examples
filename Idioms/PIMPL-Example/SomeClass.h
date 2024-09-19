#pragma once

namespace PimplNamespase {
    class PimplClass; // PIMPLE - указатель на реализацию PimpleNamespase::PimpleClass
}

class AnotherClass; // PIMPLE - указатель на реализацию AnotherClass

class SomeClass
{
public:
    SomeClass();
    ~SomeClass();

    void print();

private:
    PimplNamespase::PimplClass* m_pimplClass;
    AnotherClass* m_anotherClass;

};

class AnotherClass
{
public:
    AnotherClass();
    ~AnotherClass();

    void print();

};
