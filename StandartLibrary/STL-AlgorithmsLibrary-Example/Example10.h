#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Sorting and related operationsModifying sequence operations
 * =======================================================================================================================================================================
 *
 * Partitioning operations
 * - is_partitioned
 * - ranges::is_partitioned
 * - partition
 * - ranges::partition
 * - partition_copy
 * - ranges::partition_copy
 * - stable_partition
 * - ranges::stable_partition
 * - partition_point
 * - ranges::partition_point
 *
 */

namespace Example10 {

struct MyClass
{
    int id;
    std::string name;
};

namespace PO1 { // ------------------------------------ is_partitioned ()

void test()
{
    std::vector<MyClass> v{
        { 2, "name2" },
        { 4, "name4" },
        { 6, "name6" },
        { 8, "name8" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << "is_partitioned:" << std::boolalpha << std::is_partitioned(v.begin(), v.end(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    }) << std::endl;
}

} // namespace PO1



namespace PO2 { // ------------------------------------ ranges::is_partitioned ()

void test()
{
    std::vector<MyClass> v{
        { 2, "name2" },
        { 4, "name4" },
        { 6, "name6" },
        { 8, "name8" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << "is_partitioned:" << std::boolalpha << std::ranges::is_partitioned(v, [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    }) << std::endl;
}

} // namespace PO2



namespace PO3 { // ------------------------------------ partition (переносит элементы удовлетворяющие условию в начало диапазона)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    auto it = std::partition(v1.begin(), v1.end(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });

    std::copy(std::begin(v1), it, std::back_inserter(v2));
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace PO3



namespace PO4 { // ------------------------------------ ranges::partition (выделяет поддиапазон элементов по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    auto it = std::ranges::partition(v1, [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    for (const auto& el : it)
    {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    }
}

} // namespace PO4



namespace PO5 { // ------------------------------------ partition_copy (выделяет два поддиапаза элементов по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;
    std::vector<MyClass> v3;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::partition_copy(v1.begin(), v1.end(), std::back_inserter(v2), std::back_inserter(v3), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;

    std::for_each(v3.cbegin(), v3.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace PO5



namespace PO6 { // ------------------------------------ ranges::partition_copy (выделяет два поддиапаза элементов по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;
    std::vector<MyClass> v3;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::partition_copy(v1, std::back_inserter(v2), std::back_inserter(v3), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;

    std::for_each(v3.cbegin(), v3.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace PO6



namespace PO7 { // ------------------------------------ stable_partition (переставляет значения диапазона относительно середины по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::stable_partition(v1.begin(), v1.end(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace PO7



namespace PO8 { // ------------------------------------ ranges::stable_partition (переставляет значения диапазона относительно середины по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::ranges::stable_partition(v1, [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace PO8



namespace PO9 { // ------------------------------------ partition_point (переставляет значения диапазона и возвращает точку граничную)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    const auto pp = std::partition_point(v1.cbegin(), v1.cend(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    const auto i = std::distance(v1.cbegin(), pp);

    std::cout << "Partition point is at " << i << "; v[" << i << "] = " << "{ id: " << (*pp).id << ", name: " << (*pp).name << " }" << std::endl;
}

} // namespace PO9



namespace PO10 { // ------------------------------------ ranges::partition_point (переставляет значения диапазона и возвращает точку граничную)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    const auto pp = std::ranges::partition_point(v1, [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    const auto i = std::ranges::distance(v1.cbegin(), pp);

    std::cout << "Partition point is at " << i << "; v[" << i << "] = " << "{ id: " << (*pp).id << ", name: " << (*pp).name << " }" << std::endl;
}

} // namespace PO10

} // namespace Example10
