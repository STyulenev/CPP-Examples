#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Order-changing operations:
 * - reverse
 * - ranges::reverse
 * - reverse_copy
 * - ranges::reverse_copy
 * - rotate
 * - ranges::rotate
 * - rotate_copy
 * - ranges::rotate_copy
 * - shift_left
 * - shift_right
 * - ranges::shift_left
 * - ranges::shift_right
 * - random_shuffle
 * - shuffle
 * - ranges::shuffle
 *
 * Sampling operations:
 * - sample
 * - ranges::sample
 *
 */

namespace Example9 {

struct MyClass
{
    int id;
    std::string name;
};

namespace OCP1 { // ------------------------------------ reverse (разворот диапазона)

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
    std::reverse(v.begin(), v.end());
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP1



namespace OCP2 { // ------------------------------------ ranges::reverse (разворот диапазона)

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
    std::ranges::reverse(v);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP2



namespace OCP3 { // ------------------------------------ reverse_copy (разворот диапазона с копированием в другой)

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

    std::cout << std::endl;
    std::reverse_copy(v1.cbegin(), v1.cend(), std::back_inserter(v2));
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP3



namespace OCP4 { // ------------------------------------ reverse_copy (разворот диапазона с копированием в другой)

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

    std::cout << std::endl;
    std::ranges::reverse_copy(v1, std::back_inserter(v2));
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP4



namespace OCP5 { // ------------------------------------ shift_left (сдвиг элементов диапазона влево)

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
    std::shift_left(v.begin(), v.end(), 2);
    std::cout << std::endl;

    // Последние два элемента будут иметь значения UB
    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP5



namespace OCP6 { // ------------------------------------ shift_right (сдвиг элементов диапазона вправо)

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
    std::shift_right(v.begin(), v.end(), 2);
    std::cout << std::endl;

    // Первые два элемента будут иметь значения UB
    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP6



namespace OCP7 { // ------------------------------------ ranges::shift_left (сдвиг элементов диапазона влево)

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
    // C++23
    //std::ranges::shift_left(v, 2);
    std::cout << std::endl;

    // Последние два элемента будут иметь значения UB
    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP7



namespace OCP8 { // ------------------------------------ ranges::shift_right (сдвиг элементов диапазона вправо)

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
    // C++23
    //std::ranges::shift_right(v, 2);
    std::cout << std::endl;

    // Первые два элемента будут иметь значения UB
    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP8



namespace OCP9 { // ------------------------------------ random_shuffle (случайно переставляет элементы)

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

    std::random_device rd;
    std::mt19937 g(rd());

    std::cout << std::endl;
    // Устарела
    //std::random_shuffle(v.begin(), v.end(), g);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP9



namespace OCP10 { // ------------------------------------ shuffle (случайно переставляет элементы)

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

    std::random_device rd;
    std::mt19937 g(rd());

    std::cout << std::endl;
    std::shuffle(v.begin(), v.end(), g);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP10



namespace OCP11 { // ------------------------------------ ranges::shuffle (случайно переставляет элементы)

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

    std::random_device rd;
    std::mt19937 g(rd());

    std::cout << std::endl;
    std::ranges::shuffle(v, g);
    std::cout << std::endl;

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace OCP11



namespace SO1 { // ------------------------------------ sample (берёт N случайных элементов из диапазона и записывает в другой)

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

    std::cout << std::endl;
    std::sample(v1.begin(), v1.end(), std::back_inserter(v2), 4, std::mt19937 {std::random_device{}()});
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO1



namespace SO2 { // ------------------------------------ ranges::sample (берёт N случайных элементов из диапазона и записывает в другой)

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

    std::cout << std::endl;
    std::ranges::sample(v1, std::back_inserter(v2), 4, std::mt19937 {std::random_device{}()});
    std::cout << std::endl;

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace SO2

} // namespace Example9
