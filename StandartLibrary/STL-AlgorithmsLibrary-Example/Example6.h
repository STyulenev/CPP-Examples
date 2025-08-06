#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Transformation operations:
 * - transform
 * - ranges::transform
 * - replace
 * - replace_if
 * - ranges::replace
 * - ranges::replace_if
 * - replace_copy
 * - replace_copy_if
 * - ranges::replace_copy
 * - ranges::replace_copy_if
 *
 */

namespace Example6 {

struct MyClass
{
    int id;
    std::string name;
};

inline bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

namespace TO1 { // ------------------------------------ transform (проверяет, что все элементы подходят под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::transform(v.begin(), v.end(), v.begin(), [](MyClass& el) -> MyClass {
        el.id++;
        el.name += ".";
        return el;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO1



namespace TO2 { // ------------------------------------ ranges::transform (проверяет, что все элементы подходят под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::ranges::transform(v, v.begin(), [](MyClass& el) -> MyClass {
        el.id++;
        el.name += ".";
        return el;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO2



namespace TO3 { // ------------------------------------ replace (заменяет элемент на другой)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::replace(v.begin(), v.end(), MyClass{ 1, "name1" }, MyClass{ 0, "name0" });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO3



namespace TO4 { // ------------------------------------ replace_if (заменяет элемент на другой по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::replace_if(v.begin(), v.end(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    }, MyClass{ 0, "name0" });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO4



namespace TO5 { // ------------------------------------ replace_copy (заменяет элемент на другой и копирует диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 0, "name0" },
        { 0, "name0" },
        { 2, "name2" }
    };

    std::vector<MyClass> v2{v1.size()};

    std::replace_copy(v1.begin(), v1.end(), v2.begin(), MyClass{ 0, "name0" }, MyClass{ 3, "name3" });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO5



namespace TO6 { // ------------------------------------ replace_copy_if (заменяет элемент на другой и копирует диапазон по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size()};

    std::replace_copy_if(v1.begin(), v1.end(), v2.begin(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    }, MyClass{ 0, "name0" });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO6



namespace TO7 { // ------------------------------------ ranges::replace_copy (заменяет элемент на другой и копирует диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 0, "name0" },
        { 0, "name0" },
        { 2, "name2" }
    };

    std::vector<MyClass> v2{v1.size()};

    std::ranges::replace_copy(v1, v2.begin(), MyClass{ 0, "name0" }, MyClass{ 3, "name3" });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO7



namespace TO8 { // ------------------------------------ ranges::replace_copy (заменяет элемент на другой и копирует диапазон по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size()};

    std::ranges::replace_copy_if(v1, v2.begin(), [](const MyClass& el) -> bool {
            return el.id % 2 == 0;
        }, MyClass{ 0, "name0" });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace TO8

} // namespace Example6
