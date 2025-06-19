#pragma once

#include <iostream>

/*
 * constexpr - это спецификатор в C++, который позволяет вычислять выражения во время компиляции.
 *
 * Важные ограничения:
 * - Функция constexpr должна иметь хотя бы один путь выполнения, который не содержит return
 * - В теле функции constexpr разрешены только простые операторы
 * - Все параметры функции constexpr должны быть константными выражениями
 * - Нельзя использовать try-catch и goto в constexpr-функциях
 *
 * Использование constexpr позволяет:
 * - Повысить производительность за счет вычислений во время компиляции
 * - Обеспечить безопасность типов
 * - Сделать код более читаемым и поддерживаемым
 * - Избежать ошибок времени выполнения
 */

namespace Example2 {

/*
 * Константные выражения
 */
void test1()
{
    constexpr double pi2 = 2 * 3.14159265359;
}

/*
 * Функции constexpr
 */
constexpr int square(int x) {
    return x * x;
}

void test2()
{
    std::cout << "Square of 5 is: " << square(5) << std::endl;
}

/*
 * Конструкторы constexpr
 *
 * Конструкторы constexpr нужны для улучшения производительности кода, позволяя определённым вычислениям проводиться на этапе компиляции,
 * а не во время выполнения программы.
 */
class Point {
    int x, y;
public:
    constexpr Point(int x, int y) : x(x), y(y) {}
};

void test3()
{
    Point p(5, 5);
}

/*
 * Массивы переменной длины
 */
void test4()
{
    constexpr int size = 42;
    int array[size];
}

/*
 * Выражения в switch
 */
constexpr int get_day() { return 5; }

void test5()
{
    switch (get_day()) {
    case 5:
        // ...
        break;
    default:
        return;
    }
}

/*
 * Размеры массивов при получении из функции
 */
constexpr int array_size() { return 10; }

void test6()
{
    int arr[array_size()];
}

/*
 * Шаблоны
 */
template<typename T>
void status()
{
    if constexpr (std::is_same_v<T, int>) {
        std::cout << "T is int" << std::endl;
    } else {
        std::cout << "T is not int" << std::endl;
    }
}

void test7()
{
    status<int>();
}

/*
 * Статические члены constexpr
 */
struct SomeClass {
    static constexpr int max_value = 100;
};

void test8()
{
    std::cout << SomeClass::max_value << std::endl;
}

/*
 * Указатели constexpr
 */
static const int some_const_var = 10;

void test9()
{
    constexpr const int* ptr = &some_const_var;
}

/*
 * Литералы пользовательских типов
 */
unsigned long long operator "" _min(unsigned long long minutes)
{
    return minutes * 60;
}

void test10()
{
    std::cout << "5 min = " << 5_min << std::endl;
}

} // namespace Example2
