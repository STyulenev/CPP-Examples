#pragma once

class SomeClass1; // Forward declaration

class SomeClass2
{
private:
    SomeClass1* m_someClass;

public:
    SomeClass2();
    ~SomeClass2();

    void setSomeClass(SomeClass1* someClass);

    void print();
    void printSC2();

};
