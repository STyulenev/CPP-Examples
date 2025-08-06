#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Swap operations:
 * - swap
 * - swap_ranges
 * - ranges::swap_ranges
 * - iter_swap
 *
 */

namespace Example5 {

struct MyClass
{
    int id;
    std::string name;

    friend void swap(MyClass& lhs, MyClass& rhs)
    {
        std::swap(lhs.id, rhs.id);
        std::swap(lhs.name, rhs.name);
    }

    friend std::ostream& operator<<(std::ostream& os, MyClass const& el)
    {
        return os << "{ id: " << el.id << ", name: " << el.name << " }";
    }
};

namespace SO1 { // ------------------------------------ swap (обменивает значения двух объектов)

void test()
{
    MyClass mc1{ 1, "name1" };
    MyClass mc2{ 2, "name2" };

    std::cout << "1. " << mc1 << std::endl;
    std::cout << "2. " << mc2 << std::endl;

    std::swap(mc1, mc2);

    std::cout << "1. " << mc1 << std::endl;
    std::cout << "2. " << mc2 << std::endl;
}

} // namespace SO1



namespace SO2 { // ------------------------------------ swap_ranges (обменивает значения двух диапазонов объектов)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{
        { 5, "name5" },
        { 6, "name6" },
        { 7, "name7" },
        { 8, "name8" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::swap_ranges(v1.begin(), v1.end(), v2.begin());
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO2



namespace SO3 { // ------------------------------------ swap_ranges (обменивает значения двух диапазонов объектов)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{
        { 5, "name5" },
        { 6, "name6" },
        { 7, "name7" },
        { 8, "name8" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::swap_ranges(v1, v2);
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO3



namespace SO4 { // ------------------------------------ iter_swap (обменивает значения двух объектов в диапазоне)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::iter_swap(v.begin(), v.end() - 1);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO4

} // namespace Example5
