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

inline void test4()
{
    PROGRAMM_LOG("inline void test3()");

    REGISTER_ENUM_VALUE(MyEnum, one, two, three);
    REGISTER_ENUM(MyEnum, one, two, three);

    START_SWITCH (MyEnum::fromStr("two"))
    //case MyEnum::UNKNOWN:
    case MyEnum::one:
        std::cout << "one" << std::endl;
        break;
    case MyEnum::two:
        std::cout << "two" << std::endl;
        break;
    case MyEnum::three:
        std::cout << "three" << std::endl;
        break;
    STOP_SWITCH
}

struct MyClass
{
    MyClass() = default;

    DISABLE_CLASS_COPY(MyClass)
    DISABLE_CLASS_MOVE(MyClass)
};

} // namespace Example1
