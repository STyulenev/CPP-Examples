#pragma once

#include <iostream>
#include <vector>

namespace mystd {
    const char* str = "test";
    // ...
}

namespace Exampel1 {

/*
 * Использование директивы using namespace для использования всех имён из указанного пространства имён.
 */
void test1()
{
    using namespace std;
    using namespace mystd;

    cout << str << endl;
}

/*
 * Использование using-объявления для отдельных имён из пространства имён.
 */
void test2()
{
    using std::cout;
    using std::endl;
    using mystd::str;

    cout << str << endl;
}

/*
 * Создание псевдонимов типов.
 */
void test3()
{
    using Integer = int;

    Integer number = 10;

    std::cout << "number = " << number << std::endl;
}

/*
 * Создание псевдонимов типов для шаблонов.
 */
template <typename T>
using Vector = std::vector<T>;

void test4()
{
    Vector<int> v = { 1, 2, 3 };

    for (auto i : v) {
        std::cout << "number = " << i << ", ";
    }

    std::cout << std::endl;
}

} // namespace Exampel1
