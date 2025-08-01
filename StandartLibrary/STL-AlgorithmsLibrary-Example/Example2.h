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



namespace SO15 { // ------------------------------------ ranges::find_last (ищет последнее вхождение элемента по эталону)

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



namespace SO16 { // ------------------------------------ ranges::find_last_if (ищет последнее вхождение элемента по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" }, // #0
        { 1, "name1" }, // #1
        { 1, "name1" }, // #2
        { 4, "name4" }  // #3
    };

    auto it = std::ranges::find_last_if(v, [](const MyClass& mc) -> bool {
        return mc.id == 1 && mc.name == "name1";
    });

    int id = std::ranges::distance(v.begin(), it.begin());

    if (id != v.size())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << v.at(id).id << ", name: " << v.at(id).name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO16



namespace SO17 { // ------------------------------------ ranges::find_last_if_not (ищет последнее вхождение элемента по условию + НЕ)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" }, // #0
        { 1, "name1" }, // #1
        { 1, "name1" }, // #2
        { 4, "name4" }  // #3
    };

    auto it = std::ranges::find_last_if_not(v, [](const MyClass& mc) -> bool {
        return mc.id == 1 && mc.name == "name1";
    });

    int id = std::ranges::distance(v.begin(), it.begin());

    if (id != v.size())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << v.at(id).id << ", name: " << v.at(id).name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO17 find_end




namespace SO18 { // ------------------------------------ find_end (ищет последнее вхождение поддиапазона в диапазоне)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 2, "name2" },
        { 3, "name3" }
    };

    auto it = std::find_end(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());

    if (it != v1.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO18



namespace SO19 { // ------------------------------------ ranges::find_end (ищет последнее вхождение поддиапазона в диапазоне)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 2, "name2" },
        { 3, "name3" }
    };

    auto it = std::ranges::find_end(v1, v2);

    int id = std::ranges::distance(v1.begin(), it.begin());

    if (id != v1.size())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << v1.at(id).id << ", name: " << v1.at(id).name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO19



namespace SO20 { // ------------------------------------ find_first_of (ищет первое вхождение поддиапазона в диапазоне)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 2, "name2" },
        { 3, "name3" }
    };

    auto it = std::find_first_of(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());

    if (it != v1.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO20



namespace SO21 { // ------------------------------------ ranges::find_first_of (ищет первое вхождение поддиапазона в диапазоне)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 2, "name2" },
        { 3, "name3" }
    };

    auto it = std::ranges::find_first_of(v1, v2);

    if (it.base() != nullptr)
    {
        std::cout << "Ok" << std::endl;
        std::cout << "{ id: " << it->id << ", name: " << it->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace SO21



namespace SO22 { // ------------------------------------ adjacent_find (ищет первые два соседних элемента подходящие под == < > <= >=)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    //auto it = std::adjacent_find(v.cbegin(), v.cend());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::greater<MyClass>());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::less<MyClass>());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::less_equal<MyClass>());
    auto it = std::adjacent_find(v.cbegin(), v.cend(), std::greater_equal<MyClass>());

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

} // namespace SO22



namespace SO23 { // ------------------------------------ ranges::adjacent_find (ищет первые два соседних элемента подходящие под == < > <= >=)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    //auto it = std::adjacent_find(v.cbegin(), v.cend());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::greater<MyClass>());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::less<MyClass>());
    //auto it = std::adjacent_find(v.cbegin(), v.cend(), std::less_equal<MyClass>());
    auto it = std::ranges::adjacent_find(v, std::greater_equal<MyClass>());

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

} // namespace SO23



namespace SO24 { // ------------------------------------ count (считает количество элементов по эталону)

void test()
{
    std::vector<MyClass> v{
       { 1, "name1" },
       { 2, "name2" },
       { 3, "name3" },
       { 2, "name2" },
       { 2, "name2" },
       { 4, "name4" },
       { 5, "name5" }
    };

    int result = std::count(v.cbegin(), v.cend(), MyClass{ 2, "name2" });

    std::cout << "count = " << result << std::endl;
}

} // namespace S24



namespace SO25 { // ------------------------------------ count_if (считает количество элементов по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    int result = std::count_if(v.cbegin(), v.cend(), [](const MyClass& mc) -> bool {
        return mc.id == 1 && mc.name == "name1";
    });

    std::cout << "count = " << result << std::endl;
}

} // namespace S25



namespace SO26 { // ------------------------------------ ranges::count (считает количество элементов по эталону)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    int result = std::ranges::count(v, MyClass{ 2, "name2" });

    std::cout << "count = " << result << std::endl;
}

} // namespace S26



namespace SO27 { // ------------------------------------ ranges::count_if (считает количество элементов по условию)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    int result = std::ranges::count_if(v, [](const MyClass& mc) -> bool {
        return mc.id == 1 && mc.name == "name1";
    });

    std::cout << "count = " << result << std::endl;
}

} // namespace S27



namespace SO28 { // ------------------------------------ mismatch (ищет первое несовпадение двух диапазонов)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 1, "name1" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    auto [it1, it2] = std::mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (it1 != v1.end() && it2 != v2.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "1 = { id: " << it1->id << ", name: " << it1->name << " }" << std::endl;
        std::cout << "2 = { id: " << it2->id << ", name: " << it2->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace S28



namespace SO29 { // ------------------------------------ ranges::mismatch (ищет первое несовпадение двух диапазонов)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 1, "name1" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    auto [it1, it2] = std::ranges::mismatch(v1, v2);

    if (it1 != v1.end() && it2 != v2.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "1 = { id: " << it1->id << ", name: " << it1->name << " }" << std::endl;
        std::cout << "2 = { id: " << it2->id << ", name: " << it2->name << " }" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace S29



namespace SO30 { // ------------------------------------ equal (сравнивает диапазоны)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 1, "name1" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    bool result = std::equal(v1.begin(), v1.end(), v2.begin(), v2.end());

    std::cout << "std::equal = " << std::boolalpha << result << std::endl;
}

} // namespace S30



namespace SO31 { // ------------------------------------ ranges::equal (сравнивает диапазоны)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 5, "name5" }
    };

    std::vector<MyClass> v2{
        { 1, "name1" },
        { 2, "name2" },
        { 2, "name2" },
        { 4, "name4" },
        { 5, "name5" }
    };

    bool result = std::ranges::equal(v1.begin(), v1.end(), v2.begin(), v2.end());

    std::cout << "std::ranges::equal = " << std::boolalpha << result << std::endl;
}

} // namespace S31



namespace SO32 { // ------------------------------------ search (ищет первое вхождение поддиапазона в диапазоне)

void test()
{
    std::string str = "0qwerty123qwerty456qwerty789";
    std::string qwerty = "qwerty";

    auto it = std::search(str.begin(), str.end(), qwerty.begin(), qwerty.end());

    if (it != str.end())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "it = " << *it << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace S32



namespace SO33 { // ------------------------------------ search (ищет первое вхождение поддиапазона в диапазоне)

void test()
{
    std::string str = "0qwerty123qwerty456qwerty789";
    std::string qwerty = "qwerty";

    auto it = std::ranges::search(str, qwerty);

    int id = std::ranges::distance(str.begin(), it.begin());

    if (id != str.size())
    {
        std::cout << "Ok" << std::endl;
        std::cout << "id = " << id << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

} // namespace S33

} // namespace Example2
