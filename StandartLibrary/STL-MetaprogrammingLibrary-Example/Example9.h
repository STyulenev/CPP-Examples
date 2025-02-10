#pragma once

#include <ratio>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                                  Compile-time rational arithmetic
 * =======================================================================================================================================================================
 *
 * - Compile-time fractions
 *
 * Compile-time rational arithmetic:
 * - ratio_add
 * - ratio_subtract
 * - ratio_multiply
 * - ratio_divide
 *
 * Compile-time rational comparison
 * - ratio_equal
 * - ratio_not_equal
 * - ratio_less
 * - ratio_less_equal
 * - ratio_greater
 * - ratio_greater_equal
 *
 */

namespace Example9 { // ------------------------------------ Compile-time fractions

namespace CTF_1 {

void test()
{
    typedef std::ratio<1, 1000> milli; // milli 10^3

    std::cout << milli::num << "^-" << milli::den << std::endl;
}

} // namespace CTF_1

namespace CTRA_1 { // ------------------------------------ ratio_add

void test()
{
    using first  = std::ratio<1, 1000>;
    using second = std::ratio<2, 1000>;
    using sum    = std::ratio_add<first, second>;

    std::cout << "1/1000 + 2/1000 = " << sum::num << '/' << sum::den << std::endl;
}

} // namespace CTRA_1



namespace CTRA_2 { // ------------------------------------ ratio_subtract

void test()
{
    using first  = std::ratio<3, 1000>;
    using second = std::ratio<1, 1000>;
    using sum    = std::ratio_subtract<first, second>;

    std::cout << "3/1000 - 1/1000 = " << sum::num << '/' << sum::den << std::endl;
}

} // namespace CTRA_2



namespace CTRA_3 { // ------------------------------------ ratio_multiply

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using sum    = std::ratio_multiply<first, second>;

    std::cout << "3/5 * 1/5 = " << sum::num << '/' << sum::den << std::endl;
}

} // namespace CTRA_3



namespace CTRA_4 { // ------------------------------------ ratio_divide

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using sum    = std::ratio_divide<first, second>;

    std::cout << "3/5 : 1/5 = " << sum::num << '/' << sum::den << std::endl;
}

} // namespace CTRA_4



namespace CTRC_1 { // ------------------------------------ ratio_equal

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using result = std::ratio_equal<first, second>;

    std::cout << "3/5 " << (result::value ? "==" : "!==") << " 1/5" << std::endl;
}

} // namespace CTRC_1



namespace CTRC_2 { // ------------------------------------ ratio_not_equal

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using result = std::ratio_not_equal<first, second>;

    std::cout << "3/5 " << (result::value ? "!==" : "==") << " 1/5" << std::endl;
}

} // namespace CTRC_2



namespace CTRC_3 { // ------------------------------------ ratio_less

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using result = std::ratio_less<first, second>;

    std::cout << "3/5 " << (result::value ? "<" : ">") << " 1/5" << std::endl;
}

} // namespace CTRC_3



namespace CTRC_4 { // ------------------------------------ ratio_less_equal

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<15, 25>;
    using result = std::ratio_less_equal<first, second>;

    std::cout << "3/5 " << (result::value ? "<=" : ">") << " 15/25" << std::endl;
}

} // namespace CTRC_4



namespace CTRC_5 { // ------------------------------------ ratio_greater

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<1, 5>;
    using result = std::ratio_greater<first, second>;

    std::cout << "3/5 " << (result::value ? ">" : "<") << " 1/5" << std::endl;
}

} // namespace CTRC_5



namespace CTRC_6 { // ------------------------------------ ratio_greater_equal

void test()
{
    using first  = std::ratio<3, 5>;
    using second = std::ratio<15, 25>;
    using result = std::ratio_greater_equal<first, second>;

    std::cout << "3/5 " << (result::value ? ">=" : "<") << " 1/5" << std::endl;
}

} // namespace CTRC_6

} // namespace Example9
