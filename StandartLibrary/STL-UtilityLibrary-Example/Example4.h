#pragma once

#include <functional>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                         Function objects
 * =======================================================================================================================================================================
 *
 * Partial function application:
 * - bind_front
 * - bind_back
 * - bind
 * - is_bind_expression
 * - is_placeholder
 * - _1, _2, _3, _4, ...
 *
 *
 */

namespace Example4 {


namespace PFA {

void divide(int a, int b)
{
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
}

void test()
{
    auto swapped = std::bind(divide, std::placeholders::_2, std::placeholders::_1);

    swapped(10, 2);
    swapped(5, 15);
}

} // namespace PFA

} // namespace Example4
