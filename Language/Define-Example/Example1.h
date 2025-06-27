#pragma once

#include "Definations.h"


namespace Example1 {

FWD_DCL(MyClass)

CREATE_TYPE_CLASS(MyClass1)
CREATE_TYPE_CLASS(MyClass2)

inline void test1()
{
    PROGRAMM_LOG("inline void test1()");

    MyClassSPtr ptr = std::make_shared<MyClass>();
}

inline void test2()
{
    PROGRAMM_LOG("inline void test2()");

    MyClass1 mc1;
    mc1.doTask();

    MyClass1 mc2;
    mc2.doTask();
}

inline void test3()
{
    PROGRAMM_LOG("inline void test3()");

    std::cout << "MAX(1, 2) = " << MAX(1, 2) << std::endl;
}

struct MyClass
{
    MyClass() = default;

    DISABLE_CLASS_COPY(MyClass)
    DISABLE_CLASS_MOVE(MyClass)
};

} // namespace Example1
