#include "Example1.h"
#include "Example2.h"
#include "Example3.h"

/*
 * Препроцессорные директивы — это команды, которые управляют работой препроцессора, обрабатывающего исходный код программ до их компиляции.
 */

int main()
{
    {
        //Example1::test1();
        //Example1::test2();
        //Example1::test3();
        //Example1::test4();
    }

    {
        //Example2::test1();
        //Example2::test2();
        //Example2::test3();
    }

    {
        Example3::test4();
        Example3::test5();
        Example3::test6();
        Example3::test9();
    }

    return 0;
}
