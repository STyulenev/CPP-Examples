#pragma once

#include <iostream>
#include <vector>

namespace Example1 {

typedef struct SomeStruct
{
    int a;
    int b;
    // ...
} SoStr; // Создание внешней связи

/*
 * Для создания псевдонимов структур при их написании
 */
void test1()
{
    std::cout << "\ntest1()\n\n";

    SoStr      myStruct1;
    SomeStruct myStruct2;
}

/*
 * Для создания псевдонимов типов
 */
void test2()
{
    std::cout << "\ntest2()\n\n";

    typedef int Integer; // ~ using

    Integer number = 3;
}


template <typename T>
struct Vector {
    typedef std::vector<T> type;
};

/*
 * Для создания псевдонимов типов
 */
void test3()
{
    std::cout << "\ntest2()\n\n";

    // typedef std::vector<int> VectorInt;
    // VectorInt v = { 1, 2, 3 };

    Vector<int>::type v = { 1, 2, 3 };

    for (auto i : v) {
        std::cout << "number = " << i << ", ";
    }

    std::cout << std::endl;
}

/*
 * Для создания псевдонимов типов
 */
void myPrint(const char* message)
{
    std::cout << message << std::endl;
};

/*
 * Упрощение типов указателей функций
 */
void test4()
{
    std::cout << "\ntest4()\n\n";

    // Новое имя для указателя на функцию
    typedef void(*Message)(const char* message);
    //using Message = void(*)(const char*);

    Message m = &myPrint;

    m("Hello");
}

} // namespace Example1
