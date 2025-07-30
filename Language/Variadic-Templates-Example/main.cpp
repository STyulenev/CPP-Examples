#include <iostream>
#include <vector>

/*
 * Variadic templates — это шаблоны функций или классов, принимающие переменное количество аргументов произвольного типа.
 * Они были введены в стандарт C++11 и позволяют создавать обобщённые конструкции, способные обрабатывать любое число аргументов
 * разных типов во время компиляции.
 *
 */

void print()
{
    std::cout << std::endl;
}

template <typename T> void print(const T& t)
{
    std::cout << t << std::endl;
}

template <typename First, typename... Rest>
void print(const First& first, const Rest&... rest)
{
    std::cout << first << ", ";
    print(rest...);
}

auto sqrtSum(auto... args)
{
    return ((args * args) + ...);
}

auto sum(auto... args)
{
    return (args+...);
}

auto average(auto... args)
{
    auto s =  sum(args...);
    return s / sizeof...(args);
}

int main()
{
    std::cout << "print" << std::endl;
    {
        print();
        print(1);
        print(10, 20);
        print(1, 2, 3);
        print("one", 2, "three", 4);
    }

    std::cout << "sqrtSum" << std::endl;
    {
        std::cout << "1^2 = " << sqrtSum(1) << std::endl;
        std::cout << "1^2+2^2 = " << sqrtSum(1, 2) << std::endl;
        std::cout << "1^2+2^2+3^2 = " << sqrtSum(1,  2, 3) << std::endl;
    }

    std::cout << "sum" << std::endl;
    {
        std::cout << "1 = " << sum(1) << std::endl;
        std::cout << "1+2 = " << sum(1, 2) << std::endl;
        std::cout << "1+2+3 = " << sum(1,  2, 3) << std::endl;
    }

    std::cout << "average" << std::endl;
    {
        std::cout << "1/1 = " << average(1) << std::endl;
        std::cout << "1+2 / 2 = " << average(1, 2) << std::endl;
        std::cout << "1+2+3 / 3 = " << average(1,  2, 3) << std::endl;
    }

    return 0;
}
