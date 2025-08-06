#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace Other {

struct MyClass
{
    int id;
    std::string name;
};

namespace EX1 {

template<typename IteratorType, typename Lambda>
void my_for_each(IteratorType first, IteratorType last, Lambda f)
{
    for (; first != last; ++first)
        f(*first);
}

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    my_for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace EX1

namespace EX2 {

template<typename IteratorType, typename Lambda>
void my_transform(IteratorType first, IteratorType last, IteratorType result, Lambda f)
{
    for (; first != last; ++first, ++result)
        *result = f(*first);
}

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    my_transform(v.begin(), v.end(), v.begin(), [](MyClass& el) -> MyClass {
        el.id++;
        el.name += ".";
        return el;
    });

    std::for_each(v.cbegin(), v.cend(), [](const MyClass& el) -> void {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    });
}

} // namespace EX2

} // namespace Other
