#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Non-modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Fold operations (since C++23)
 * - ranges::fold_left
 * - ranges::fold_left_first
 * - ranges::fold_right
 * - ranges::fold_right_last
 * - ranges::fold_left_with_iter
 * - ranges::fold_left_first_with_iter
 *
 */

namespace Example3 {

struct MyClass
{
    int    v1;
    double v2;
};

inline MyClass operator+(const MyClass& lhs, const MyClass& rhs)
{
    MyClass mc;

    mc.v1 = lhs.v1 + rhs.v1;
    mc.v2 = lhs.v2 + rhs.v2;

    return mc;
}

inline MyClass operator-(const MyClass& lhs, const MyClass& rhs)
{
    MyClass mc;

    mc.v1 = lhs.v1 - rhs.v1;
    mc.v2 = lhs.v2 - rhs.v2;

    return mc;
}

inline MyClass operator*(const MyClass& lhs, const MyClass& rhs)
{
    MyClass mc;

    mc.v1 = lhs.v1 * rhs.v1;
    mc.v2 = lhs.v2 * rhs.v2;

    return mc;
}

inline MyClass operator/(const MyClass& lhs, const MyClass& rhs)
{
    MyClass mc;

    // check by 0

    mc.v1 = lhs.v1 / rhs.v1;
    mc.v2 = lhs.v2 / rhs.v2;

    return mc;
}

namespace FO1 { // ------------------------------------ ranges::fold_left (свёртка диапазона слево)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 },
        { 3, 3.3 },
        { 4, 4.4 },
        { 5, 5.5 }
    };

    auto sum = std::ranges::fold_left(v, MyClass{0, 0.0}, std::plus<MyClass>());

    std::cout << "sum = { " << sum.v1 << ", " << sum.v2 << " }" << std::endl;
}

} // namespace FO1



namespace FO2 { // ------------------------------------ ranges::fold_left_first (свёртка диапазона слево + первый элемент начальный)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 },
        { 3, 3.3 },
        { 4, 4.4 },
        { 5, 5.5 }
    };

    auto sum = std::ranges::fold_left_first(v, std::minus<MyClass>());

    if (sum.has_value())
    {
        std::cout << "sum = { " << sum.value().v1 << ", " << sum.value().v2 << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace FO2



namespace FO3 { // ------------------------------------ ranges::fold_right (свёртка диапазона вправо)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 },
        { 3, 3.3 },
        { 4, 4.4 },
        { 5, 5.5 }
    };

    auto sum = std::ranges::fold_right(v, MyClass{1, 1.0}, std::multiplies<MyClass>());

    std::cout << "sum = { " << sum.v1 << ", " << sum.v2 << " }" << std::endl;
}

} // namespace FO3



namespace FO4 { // ------------------------------------ ranges::fold_right (свёртка диапазона справо + первый элемент начальный)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 }
    };

    auto sum = std::ranges::fold_right_last(v, std::divides<MyClass>());

    if (sum.has_value())
    {
        std::cout << "sum = { " << sum.value().v1 << ", " << sum.value().v2 << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace FO4



namespace FO5 { // ------------------------------------ ranges::fold_left_with_iter (свёртка диапазона влево)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 }
    };

    auto sum = std::ranges::fold_left_with_iter(v, MyClass{0, 0.0}, std::plus<MyClass>());

    std::cout << "sum = { " << sum.value.v1 << ", " << sum.value.v2 << " }" << std::endl;
}

} // namespace FO5



namespace FO6 { // ------------------------------------ ranges::fold_left_first_with_iter (свёртка диапазона влево)

void test()
{
    std::vector<MyClass> v{
        { 1, 1.1 },
        { 2, 2.2 }
    };

    auto sum = std::ranges::fold_left_first_with_iter(v, std::plus<MyClass>());

    if (sum.value.has_value())
    {
        std::cout << "sum = { " << sum.value.value().v1 << ", " << sum.value.value().v2 << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace FO6

} // namespace Example3
