#pragma once

class SomeClass
{
public:
    static SomeClass createSomeClassWithStatus_1();
    static SomeClass createSomeClassWithStatus_2();
    static SomeClass createSomeClassWithStatus_3();

    void print();

    ~SomeClass();

protected:
    SomeClass();
    SomeClass(int status);

private:
    int status;

};
