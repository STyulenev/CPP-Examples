#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * =======================================================================================================================================================================
 *                                                                Non-modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Search operations
 * - all_of
 * - any_of
 * - none_of
 * - ranges::all_of
 * - ranges::any_of
 * - ranges::none_of
 * - ranges::contains
 * - ranges::contains_subrange
 * - find
 * - find_if
 * - find_if_not
 * - ranges::find
 * - ranges::find_if
 * - ranges::find_if_not
 * - ranges::find_last
 * - ranges::find_last_if
 * - ranges::find_last_if_not
 * - find_end
 * - ranges::find_end
 * - find_first_of
 * - ranges::find_first_of
 * - adjacent_find
 * - ranges::adjacent_find
 * - count
 * - count_if
 * - ranges::count
 * - ranges::count_if
 * - mismatch
 * - ranges::mismatch
 * - equal
 * - ranges::equal
 * - search
 * - ranges::search
 * - search_n
 * - ranges::search_n
 * - ranges::starts_with
 * - ranges::ends_with
 *
 */

namespace Example2 {

struct MyClass
{
    int id;
    std::string name;
};

inline bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}



namespace SO1 { // ------------------------------------ all_of (проверяет, что все элементы подходят под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::all_of(v.cbegin(), v.cend(), [](const MyClass& el) -> bool {
        return el.id > 0 && el.id < 100;
    });

    std::cout << "all_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO1



namespace SO2 { // ------------------------------------ any_of (проверяет, что хотя бы один элемент подходит под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::any_of(v.cbegin(), v.cend(), [](const MyClass& el) -> bool {
        return el.id == 2;
    });

    std::cout << "any_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO2



namespace SO3 { // ------------------------------------ none_of (проверяет, что хотя бы один элемент подходит под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::none_of(v.cbegin(), v.cend(), [](const MyClass& el) -> bool {
        return el.id == 50;
    });

    std::cout << "none_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO3




namespace SO4 { // ------------------------------------ ranges::all_of (проверяет, что все элементы подходят под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::ranges::all_of(v,  [](const MyClass& el) -> bool {
        return el.id > 0 && el.id < 100;
    });

    std::cout << "ranges::all_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO4




namespace SO5 { // ------------------------------------ ranges::any_of (проверяет, что хотя бы один элемент подходит под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::ranges::any_of(v, [](const MyClass& el) -> bool {
        return el.id == 2;
    });

    std::cout << "ranges::any_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO5



namespace SO6 { // ------------------------------------ ranges::none_of (проверяет, что хотя бы один элемент подходит под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    bool result = std::ranges::none_of(v, [](const MyClass& el) -> bool {
        return el.id == 50;
    });

    std::cout << "ranges::none_of = " << std::boolalpha << result << std::endl;
}

} // namespace SO6




namespace SO7 { // ------------------------------------ std::ranges::contains (проверяет, есть ли элемент в диапазоне)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    MyClass mc{ 1, "name1" };

    bool result = std::ranges::contains(v, mc);

    std::cout << "std::ranges::contains = " << std::boolalpha << result << std::endl;
}

} // namespace SO7




namespace SO8 { // ------------------------------------ ranges::contains_subrange (проверяет, есть ли поддиапазон в диапазоне, порядок важен)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{
        { 1, "name1" },
        { 2, "name2" }//,
        //{ 4, "name4" }
    };

    bool result = std::ranges::contains_subrange(v1, v2);

    std::cout << "std::ranges::contains_subrange = " << std::boolalpha << result << std::endl;
}

} // namespace SO8



namespace SO9 { // ------------------------------------ find (ищет первое вхождение эталонного элемента)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::find(v.begin(), v.end(), MyClass{ 1, "name1" });

    std::cout << (it != v.end() ? "Ok" : "Error") << std::endl;
}

} // namespace SO9



namespace SO10 { // ------------------------------------ find_if (ищет первое вхождение элемента по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::find_if(v.begin(), v.end(), [](const MyClass& mc) -> bool {
        return mc.id == 2 && mc.name == "name2";
    });

    if (it != v.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO10



namespace SO11 { // ------------------------------------ find_if_not (ищет первое вхождение элемента по условию с не)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::find_if_not(v.begin(), v.end(), [](const MyClass& mc) -> bool {
        return mc.id == 1 || mc.name == "name2";
    });

    if (it != v.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO11



namespace SO12 { // ------------------------------------ ranges::find (ищет первое вхождение эталонного элемента)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::ranges::find(v, MyClass{ 1, "name1" });

    std::cout << (it != v.end() ? "Ok" : "Error") << std::endl;
}

} // namespace SO12



namespace SO13 { // ------------------------------------ ranges::find_if (ищет первое вхождение элемента по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::ranges::find_if(v, [](const MyClass& mc) -> bool {
        return mc.id == 2 && mc.name == "name2";
    });

    if (it != v.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO13



namespace SO14 { // ------------------------------------ ranges::find_if_not (ищет первое вхождение элемента по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto it = std::ranges::find_if_not(v, [](const MyClass& mc) -> bool {
        return mc.id == 1 || mc.name == "name2";
    });

    if (it != v.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO14



namespace SO15 { // ------------------------------------ ranges::find_last (ищет последнее вхождение элемента по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" }, // #0
        { 1, "name1" }, // #1
        { 1, "name1" }, // #2
        { 4, "name4" }  // #3
    };

    auto it = std::ranges::find_last(v, MyClass{ 1, "name1" });

    std::cout << (std::ranges::distance(v.begin(), it.begin()) == 2 ? "Ok" : "Error") << std::endl;
}

} // namespace SO15

} // namespace Example2
