#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Copy operations
 * - copy
 * - copy_if
 * - ranges::copy
 * - ranges::copy_if
 * - copy_n
 * - ranges::copy_n
 * - copy_backward
 * - ranges::copy_backward
 * - move
 * - ranges::move
 * - move_backward
 * - ranges::move_backward
 *
 */

namespace Example4
{

struct MyClass
{
    int id;
    std::string name;

    MyClass() {}
    MyClass(int id, const std::string& name) : id(id), name(name) {}

    MyClass(const MyClass& copy)
    {
        this->id = copy.id;
        this->name = copy.name;
    }

    MyClass(MyClass&& moved) // ссылка rvalue
    {
        this->id = moved.id;
        this->name = moved.name;

        moved.id = -1;
        moved.name = "";
    }

    MyClass& operator=(const MyClass& copy)
    {
        if (&copy!= this)
        {
            this->id = copy.id;
            this->name = copy.name;
        }

        return *this;
    }

    MyClass& operator=(MyClass&& moved)
    {
        if (&moved != this)
        {
            this->id = moved.id;
            this->name = moved.name;

            moved.id = -1;
            moved.name = "";
        }

        return *this;
    }
};

namespace CO1 { // ------------------------------------ copy (копирует диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::copy(v1.cbegin(), v1.cend(), std::back_inserter(v2));

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO1



namespace CO2 { // ------------------------------------ copy_if (копирует элементы диапазона по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::copy_if(v1.cbegin(), v1.cend(), std::back_inserter(v2), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO2



namespace CO3 { // ------------------------------------ ranges::copy (копирует диапазон)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::ranges::copy(v1, std::back_inserter(v2));

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO1



namespace CO4 { // ------------------------------------ ranges::copy_if (копирует элементы диапазона по условию)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::ranges::copy_if(v1, std::back_inserter(v2), [](const MyClass& el) -> bool {
        return el.id % 2 == 0;
    });

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO2



namespace CO5 { // ------------------------------------ copy_backward (копирует диапазон в другой, начиная заполнять его с конца)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size() + 1}; // Нужно заранее выделить место
    v2[0] = { 0, "name0" };

    std::copy_backward(v1.begin(), v1.end(), v2.end());

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO5



namespace CO6 { // ------------------------------------ ranges::copy_backward (копирует диапазон в другой, начиная заполнять его с конца)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size() + 1}; // Нужно заранее выделить место
    v2[0] = { 0, "name0" };

    std::ranges::copy_backward(v1, v2.end());

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO6



namespace CO7 { // ------------------------------------ move (перемещает элементы диапазона в другой)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::move(v1.begin(), v1.end(), std::back_inserter(v2));

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO7



namespace CO8 { // ------------------------------------ ranges::move (перемещает элементы диапазона в другой, начиная заполнять его с конца)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2;

    std::ranges::move(v1, std::back_inserter(v2));

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO8



namespace CO9 { // ------------------------------------ move_backward (перемещает элементы диапазона в другой)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size() + 1}; // Нужно заранее выделить место
    v2[0] = { 0, "name0" };

    std::move_backward(v1.begin(), v1.end(), v2.end());

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO9



namespace CO10 { // ------------------------------------ ranges::move_backward (перемещает элементы диапазона в другой)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{v1.size() + 1}; // Нужно заранее выделить место
    v2[0] = { 0, "name0" };

    std::ranges::move_backward(v1, v2.end());

    std::for_each(v2.cbegin(), v2.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });

    std::for_each(v1.cbegin(), v1.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace CO10

} // namespace Example4
