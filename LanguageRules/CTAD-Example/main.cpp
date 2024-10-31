#include <iostream>
#include <tuple>

#include "SomeClass.h"

/*
 * Class Template Argument Deduction (CTAD) - автоматический вывод типа параметра шаблона класса. Это новая возможность из C++17. Раньше автоматически выводились
 * только типы переменных (auto) и параметры шаблонов функций, из-за чего и возникли вспомогательные функции типа std::make_pair, std::make_tuple и т. п.
 * Теперь они по большей части не нужны, т. к. компилятор способен автоматически вывести и параметры шаблонов классов:
 *
 */

int main()
{

#if  __cplusplus == 201103L
    std::cout << "C++ 11" << std::endl;
    return -1;
#elif  __cplusplus == 201402L
    std::cout << "C++ 14" << std::endl;
    return -1;
#elif __cplusplus == 201703L
    std::cout << "C++ 17" << std::endl;
#elif __cplusplus == 202003L
    std::cout << "C++ 20" << std::endl;
#else
    std::cout << "Unknown standart" << std::endl;
    return -1;
#endif

    /*
     * CTAD для std::pair
     */
    {
        std::pair pair1(false, 45.67);               // ОК, std::pair<bool, double>, отработал CTAD
        std::pair<bool, double> pair2(false, 45.67); // ОК, тип указан вручную
        std::pair pair3 { 1u, 2u };                  // ОК, std::pair<unsigned int, unsigned int> отработал CTAD
    }

    /*
     * CTAD для std::tuple
     */
    {
        std::tuple tup(123, 'a', 40.0);       // ОК, std::tuple<int, char, double>, отработал CTAD
        // std::tuple<> tup2(1, 2, 3);        // Частичный вывод не работает
        auto tup2 = std::make_tuple(1, 2, 3); // До C++17 и CTAD нужен std::make_tuple
    }

    /*
     * CTAD для шаблонной структуры
     */
    {
        SomePair<int, int> somePair1{ 1, 2 }; // ОК, тип указан вручную
        //SomePair<> somePair2{ 1, 2 };       // Частичный вывод не работает
        //SomePair<int> somePair3{ 1, 2 };    // Частичный вывод не работает

#if __cplusplus == 202003L // C++ 20
        SomePair somePair4{ 1, 2 };          // Ошибка для C++17, ОК для C++20
#endif
    }


    /*
     * CTAD не работает с параметрами функции
     */
    {
        // не работает
        /*auto funk = [](std::pair pair) -> void {
            // ...
        };*/

        // работает, но через шаблон
#if __cplusplus == 202003L // C++ 20
        auto funk = []<typename T, typename U>(SomePair<U, T> pair) -> void {
            // ...
        };
#endif
    }

    return 0;
}
