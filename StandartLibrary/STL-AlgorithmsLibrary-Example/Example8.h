#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Removing operations:
 * - remove
 * - remove_if
 * - ranges::remove
 * - ranges::remove_if
 * - remove_copy
 * - remove_copy_if
 * - ranges::remove_copy
 * - ranges::remove_copy_if
 * - unique
 * - ranges::unique
 * - unique_copy
 * - ranges::unique_copy
 *
 */

namespace Example8 {

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

namespace RO1 { // ------------------------------------ remove (удаление элементов через сдвиг в конец по эталону)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::remove(v.begin(), v.end(), MyClass{ 1, "name1" });
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO1



namespace RO2 { // ------------------------------------ remove_if (удаление элементов через сдвиг в конец по условию)

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
    std::remove_if(v.begin(), v.end(), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO2



namespace RO3 { // ------------------------------------ ranges::remove (удаление элементов через сдвиг в конец по эталону)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::remove(v, MyClass{ 1, "name1" });
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO3



namespace RO4 { // ------------------------------------ ranges::remove_if (удаление элементов через сдвиг в конец по условию)

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
    std::ranges::remove_if(v, [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO4



namespace RO5 { // ------------------------------------ remove_copy (переносит удаляемые элементы в другой диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::remove_copy(v1.begin(), v1.end(), std::back_inserter(v2), MyClass{ 1, "name1" });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO5



namespace RO6 { // ------------------------------------ remove_copy_if (переносит удаляемые элементы в другой диапазон по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name4" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::remove_copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO6



namespace RO7 { // ------------------------------------ remove_copy (переносит удаляемые элементы в другой диапазон по эталону)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::remove_copy(v1, std::back_inserter(v2), MyClass{ 1, "name1" });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO7



namespace RO8 { // ------------------------------------ ranges::remove_copy_if (переносит удаляемые элементы в другой диапазон по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name4" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::ranges::remove_copy_if(v1, std::back_inserter(v2), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });
    std::cout << std::endl;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
    std::cout << std::endl;
    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO8



namespace RO9 { // ------------------------------------ unique (удаление уникальных элементов через сдвиг в конец)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO9



namespace RO10 { // ------------------------------------ unique (удаление уникальных элементов через сдвиг в конец)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::sort(v.begin(), v.end());
    const auto [first, last] = std::ranges::unique(v);
    v.erase(first, last);

    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO10



namespace RO11 { // ------------------------------------ unique_copy (удаление уникальных элементов через копирование в другой диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::sort(v1.begin(), v1.end());
    std::unique_copy(v1.begin(), v1.end(), std::back_inserter(v2));
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO11



namespace RO12 { // ------------------------------------ ranges::unique_copy (удаление уникальных элементов через копирование в другой диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 1, "name1" },
        { 2, "name2" },
        { 1, "name1" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "1 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::cout << std::endl;
    std::sort(v1.begin(), v1.end());
    std::ranges::unique_copy(v1, std::back_inserter(v2));
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "2 - { id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace RO12

} // namespace Example8
