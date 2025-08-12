#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Sorting and related operationsModifying sequence operations
 * =======================================================================================================================================================================
 *
 * Sorting operations:
 * - sort
 * - ranges::sort
 * - stable_sort
 * - ranges::stable_sort
 * - partial_sort
 * - ranges::partial_sort
 * - partial_sort_copy
 * - ranges::partial_sort_copy
 * - is_sorted
 * - ranges::is_sorted
 * - is_sorted_until
 * - ranges::is_sorted_until
 * - nth_element
 * - ranges::nth_element
 *
 */

namespace Example11 {

struct MyClass
{
    int id;
    std::string name;
};

inline bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

inline bool operator>(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id > rhs.id;
}

inline bool operator<(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id < rhs.id;
}

inline bool operator>=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id >= rhs.id;
}

inline bool operator<=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id <= rhs.id;
}

namespace SO1 { // ------------------------------------ sort (сортирует диапазон)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::sort(v.begin(), v.end()/*, std::less() or std::greater()*/);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO1



namespace SO2 { // ------------------------------------ ranges::sort (сортирует диапазон)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::sort(v, std::ranges::less()); //std::ranges::greater
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO2



namespace SO3 { // ------------------------------------ stable_sort (сортирует диапазон элементов, сохраняя порядок между равными элементами)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::stable_sort(v.begin(), v.end());
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO3



namespace SO4 { // ------------------------------------ ranges::stable_sort (сортирует диапазон элементов, сохраняя порядок между равными элементами)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::stable_sort(v);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO4



namespace SO5 { // ------------------------------------ partial_sort (сортирует часть диапазона)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" },
        { 5, "name5" },
        { 6, "name6" },
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::partial_sort(v.begin(), v.begin() + 3, v.end()); // std::greater{}
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO5



namespace SO6 { // ------------------------------------ ranges::partial_sort (сортирует часть диапазона)

void test()
{
    std::vector<MyClass> v{
                           { 4, "name4" },
                           { 3, "name3" },
                           { 2, "name2" },
                           { 1, "name1" },
                           { 5, "name5" },
                           { 6, "name6" },
                           };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::partial_sort(v.begin(), v.begin() + 3, v.end()); // std::greater{}
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO6



namespace SO7 { // ------------------------------------ partial_sort_copy (сортирует часть диапазона и копирует)

void test()
{
    std::vector<MyClass> v1{
       { 4, "name4" },
       { 3, "name3" },
       { 2, "name2" },
       { 1, "name1" },
       { 5, "name5" },
       { 6, "name6" },
    };

    std::vector<MyClass> v2{4};

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::partial_sort_copy(v1.begin(), v1.begin() + 4, v2.begin(), v2.end()); // std::greater{}
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO7



namespace SO8 { // ------------------------------------ ranges::partial_sort_copy (сортирует часть диапазона и копирует)

void test()
{
    std::vector<MyClass> v1{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" },
        { 5, "name5" },
        { 6, "name6" },
    };

    std::vector<MyClass> v2{6};

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::partial_sort_copy(v1, v2); // std::greater{}
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO8



namespace SO9 { // ------------------------------------ is_sorted (проверяет отсортирован ли диапазон)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::cout << "is sorted: " << std::boolalpha << std::is_sorted(v.begin(), v.end(), std::greater{}) << std::endl;
}

} // namespace SO9



namespace SO10 { // ------------------------------------ ranges::is_sorted (проверяет отсортирован ли диапазон)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::cout << "is sorted: " << std::boolalpha << std::ranges::is_sorted(v, std::greater{}) << std::endl;
}

} // namespace SO10



namespace SO11 { // ------------------------------------ is_sorted_until (ищет размер отсортированной части диапазона, от начала до N)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" },
        { 5, "name5" },
        { 6, "name6" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    auto end = std::is_sorted_until(v.begin(), v.end(), std::greater{});

    int sorted_size = std::distance(v.begin(), end);

    std::cout << "sorted size: " << sorted_size << std::endl;
}

} // namespace SO11



namespace SO12 { // ------------------------------------ ranges::is_sorted_until (ищет размер отсортированной части диапазона, от начала до N)

void test()
{
    std::vector<MyClass> v{
        { 4, "name4" },
        { 3, "name3" },
        { 2, "name2" },
        { 1, "name1" },
        { 5, "name5" },
        { 6, "name6" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    auto end = std::ranges::is_sorted_until(v, std::greater{});

    int sorted_size = std::distance(v.begin(), end);

    std::cout << "sorted size: " << sorted_size << std::endl;
}

} // namespace SO12

// nth_element
// ::rangesnth_element

} // namespace Example11
