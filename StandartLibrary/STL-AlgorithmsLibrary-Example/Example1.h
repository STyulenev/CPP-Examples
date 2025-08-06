#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Non-modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Batch operations:
 * - for_each
 * - ranges::for_each
 * - for_each_n
 * - ranges::for_each_n
 *
 */

namespace Example1 {

struct MyClass
{
    int id;
    std::string name;
};

namespace BO1 { // ------------------------------------ for_each (для всех)

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
}

} // namespace BO1



namespace BO2 { // ------------------------------------ ranges::for_each (для всех)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::ranges::for_each(v, [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace BO2



namespace BO3 { // ------------------------------------ for_each_n (от ... до)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each_n(v.cbegin() + 1, 2, [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace BO3



namespace BO4 { // ------------------------------------ ranges::for_each_n (от ... до)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::ranges::for_each_n(v.cbegin() + 1, 2, [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace BO4

} // namespace Example1
