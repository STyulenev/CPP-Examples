#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Generation operations:
 * - fill
 * - ranges::fill
 * - fill_n
 * - ranges::fill_n
 * - generate
 * - ranges::generate
 * - generate_n
 * - ranges::generate_n
 *
 */

namespace Example7 {

struct MyClass
{
    int id;
    std::string name;
};

namespace GO1 { // ------------------------------------ fill (заполняет диапазон эталонным элементом)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::fill(v.begin(), v.end(), MyClass{ .id = 4, .name = "name"});

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO1



namespace GO2 { // ------------------------------------ ranges::fill (заполняет диапазон эталонным элементом)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::fill(v, MyClass{ .id = 4, .name = "name"});

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO2



namespace GO3 { // ------------------------------------ fill_n (заполняет n-элемнтов диапазона эталонным элементом)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::fill_n(v.begin() + 1, 3, MyClass{ .id = 4, .name = "name"});

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO3



namespace GO4 { // ------------------------------------ ranges::fill_n (заполняет n-элемнтов диапазона эталонным элементом)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::fill_n(v.begin() + 1, 3, MyClass{ .id = 4, .name = "name"});

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO4



namespace GO5 { // ------------------------------------ generate (заполняет диапазон через функцию генерации)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::generate(v.begin(), v.end(), []() -> MyClass {
        static int index = 0;

        MyClass myClass = MyClass{ .id = index, .name = "name" + std::to_string(index)};
        index++;
        return myClass;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO5



namespace GO6 { // ------------------------------------ ranges::generate (заполняет диапазон через функцию генерации)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::generate(v, []() -> MyClass {
        static int index = 0;

        MyClass myClass = MyClass{ .id = index, .name = "name" + std::to_string(index)};
        index++;
        return myClass;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO6



namespace GO7 { // ------------------------------------ generate_n (заполняет n-элемнтов диапазона через функцию генерации)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::generate_n(v.begin() + 1, 3, []() -> MyClass {
        static int index = 0;

        MyClass myClass = MyClass{ .id = index, .name = "name" + std::to_string(index)};
        index++;
        return myClass;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO7



namespace GO8 { // ------------------------------------ ranges::generate_n (заполняет n-элемнтов диапазона через функцию генерации)

void test()
{
    std::vector<MyClass> v{4};

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::generate_n(v.begin() + 1, 3, []() -> MyClass {
        static int index = 0;

        MyClass myClass = MyClass{ .id = index, .name = "name" + std::to_string(index)};
        index++;
        return myClass;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace GO8

} // namespace Example7
