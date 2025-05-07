#pragma once

#include <iostream>
#include <functional>

namespace Example1 {

void wrapper(void(*func)(void))
{
    func();
}

/*
 * Анонимная лямбда-функция (лямбда-выражение) в C++ — это функция, у которой отсутствует имя.
 * Такие функции позволяют создавать простые объекты-функции (а не классы) в любом допустимом месте программы, в том числе
 * в аргументе обычной функции.
 */
void test1()
{
    wrapper([](){
        std::cout << "\ntest1\n\n";
    });
}

/*
 * Лямбда-функция с немедленным вызывом (IIFE, Immediately-Invoked Function Expression - немедленно вызываемое функциональное выражение)
 */
void test2()
{
    [](){
        std::cout << "\ntest2\n\n";
    }();
}

/*
 * Лямбда-функция с возвращаемым значением
 */
void test3()
{
    std::cout << "\ntest3\n\n";

    auto lambda1 = []() -> int /* можно не указывать */ {
        return 5;
    };

    auto lambda2 = []() -> double /* можно не указывать */ {
        return 5.5;
    };

    // Можно начиная с C++14
    auto lambda3 = []() -> auto /* автоматический вывод типа */ {
        return "some data";
    };

    int    data1 = lambda1();
    double data2 = lambda2();
    auto   data3 = lambda3();

    std::cout << "data1 = " << data1 << std::endl;
    std::cout << "data2 = " << data2 << std::endl;
    std::cout << "data3 = " << data3 << std::endl;
}

/*
 * Рекурсивная лямда
 */
void test4()
{
    std::cout << "\ntest4\n\n";

    std::function<int(int)> factorial = [& /* для захвата себя */](int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };

    std::cout << "factorial 5: " << factorial(5) << std::endl;
}

/*
 * Передача параметров в лямбда-функцию:
 * - [&] — захват по ссылке, все переменные в автоматическом хранилище объявлены в области охвата
 * - [=] — захват по значению, все переменные копируется
 * - [x, &y] — явно захватывает x по значению, а y по ссылке
 *
 * Замыкание в контексте лямбда-функций в C++ — это возможность использовать переменные, доступные в том же контексте,
 * где описана лямбда-функция. То есть переменные, объявленные вне тела функции и не являющиеся её параметрами, становятся
 * доступными внутри функции.
 */
void test5()
{
    std::cout << "\ntest5\n\n";

    int x = 1;
    int y = 1;

    auto lambda = [x, &y]() -> void{
        // x++; // Ошибка, "operator() const" не может менять поля класса в константном методе
        y++;

        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    };

    lambda();

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

/*
 * Лямбда-функция с mutable. По умолчанию operator() типа замыкания является константным, и нельзя изменять захваченные переменные
 * внутри тела лямбда-выражения. Это помогает решить ключевое слово mutable.
 */
void test6()
{
    std::cout << "\ntest6\n\n";

    int x = 1;
    int y = 1;

    auto lambda = [x, &y]() mutable -> void{
        x++;
        y++;

        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    };

    lambda();

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

/*
 * Захват с инициализатором
 */
void test7()
{
    std::cout << "\ntest7\n\n";

    int x = 10;
    int y = 11;

    auto lambda1 = [z = x + y]() -> void {
        std::cout << "z = " << z << std::endl;
    };
    lambda1();

    auto lambda2 = [z{11}]() -> void {
        std::cout << "z = " << z << std::endl;
    };
    lambda2();
}

/*
 * Шаблонная лямбда-функция
 */
void test8()
{
    std::cout << "\ntest8\n\n";

    // Можно начиная с C++14
    auto max = [](auto a, auto b) {
        return (a > b) ? a : b;
    };

    std::cout << "max(1, 2) = "     << max(1, 2) << std::endl;
    std::cout << "max(1u, 2u) = "   << max(1u, 2u) << std::endl;
    std::cout << "max(1.1, 2.2) = " << max(1.1, 2.2) << std::endl;
}

template<class Lambda1, class Lambda2 /*, ... */>
struct Base : public Lambda1, public Lambda2
{
    Base(Lambda1 lambda1, Lambda2 lambda2) : Lambda1(std::move(lambda1)), Lambda2(std::move(lambda2)) {}

    // Переопределили оператор (), чтобы вызывать лямбду через него.
    using Lambda1::operator();
    using Lambda2::operator();
    // ...
};

/*
 * Наследование от лямбда-функций
 */
void test9()
{
    std::cout << "\ntest9\n\n";

    // Т.к. лямбда это класс, то можно от него наследоваться
    auto lambda1 = [](int x) -> int {
        return x;
    };

    auto lambda2 = [](double x) -> double {
        return x;
    };

    // Можно начиная с C++17
    Base b{lambda1, lambda2};
    std::cout << "Lambda1: " << b(1) << std::endl;
    std::cout << "Lambda2: " << b(1.1) << std::endl;
}

/*
 * constexpr лямбда-выражения
 */
void test10()
{
    std::cout << "\ntest10\n\n";

    constexpr auto Square = [] (int n) { return n * n; }; // Сработает как IIFE

    std::cout << "Square(2): " << Square(2) << std::endl;
}

} // namespace Example1
