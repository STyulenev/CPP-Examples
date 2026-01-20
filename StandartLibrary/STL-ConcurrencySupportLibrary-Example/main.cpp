#include "Example1.h"
#include "Example5.h"
#include "Example7.h"
#include "Example10.h"
#include "Other.h"

int main()
{
    {
        //Example1::T1::test();
        //Example1::T2::test();
        //Example1::T3::test();
        //Example1::T4::test();
        //Example1::T5::test();
        //Example1::T6::test();
    }

    {
        //Example5::MX1::test();
        //Example5::MX2::test();
        //Example5::MX3::test();
        //Example5::MX4::test();
        //Example5::MX5::test();

        //Example5::CO::test();
    }

    {
        //Example7::CV1::test();
        Example7::CV1_1::test();
        //Example7::CV2::test();
    }

    {
        //Example10::F1::test();
        //Example10::F2::test();
        //Example10::F3::test();
        //Example10::F4::test();
        //Example10::F5::test();
    }

    {
        //Other::Ex1::test();
        //Other::Ex2::test();
        //Other::Ex3::test();
        //Other::Ex4::test();
    }

    return 0;
}
