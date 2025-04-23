#pragma once

class SomeClass2; // Forward declaration

class SomeClass1
{
private:
    SomeClass2* m_someClass;

public:
    SomeClass1();
    ~SomeClass1();

    void setSomeClass(SomeClass2* someClass);

    void print();
    void printSC1();

};
