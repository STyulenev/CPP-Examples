#pragma once

#define NDEBUG // Отключили asserts

#include <iostream>
#include <cassert>

/*
 *
 * Примеры препроцессорных директив:
 * - #define — определяет макросы или препроцессорные идентификаторы, простейшее применение — замены в тексте программы.
 * - #include — позволяет включать текст других файлов в текст программы.
 * - #undef — отменяет действие директивы #define.
 * - #if, #ifdef, #else, #endif, #elif — директивы условной обработки.
 * - #line — управляет нумерацией строк в тексте программы.
 * - #error — задаёт текст диагностического сообщения, выводящегося при наличии ошибок.
 * - #pragma — инструкция компилятору, которая определяется реализацией. С её помощью можно указать, как осуществлять
 * выравнивание данных в структурах, запретить выдавать определённые предупреждения и так далее.
 *
 * Операторы:
 * - Оператор # текстовую лексему в строку, заключенную в кавычку.
 * - Оператор ## принимает две отдельных лексемы и склеивает их вместе, чтобы сформировать один макрос.
 *
 */

#define MESSAGE(s) std::cout << #s << std::endl;

#define DIDGITALSUM(a, b) a##b

#define FOREVER for(;;)

namespace Example3 {

// Проверить C++ код
void test1()
{
#ifdef __cplusplus // или __cpp
// C++ код
#else
// Си код
#endif
}

// Проверить ОС
void test2()
{
#ifdef __linux
// ...
#elif defined _WIN32
// ...
#else
// ...
#endif
}

// Проверить компилятор
void test3()
{
#if defined(__clang__)
  // ...
#define CLANG_COMPILER
#elif defined(__GNUC__) || defined(__GNUG__)
  // ...
#define GCC_COMPILER
#elif defined(_MSC_VER)
  // ...
#define MS_COMPILER
#else
#error "I don't know your compiler"
#endif
}

// Пример #
void test4()
{
    MESSAGE(This is log)
}

// Пример ##
void test5()
{
    std::cout << DIDGITALSUM(2, 5) << std::endl;
}

// Пример отключение asserts
void test6()
{
    assert(false);
}

// Пример #error
void test7()
{
#ifndef _WIN32
#error "Only Windows"
#endif
}

// Пример #undef
void test8()
{
#define E 2.71828

    int sumE = E + E;

#undef E // Отключение макроса

    //int sumE2 = E + E; // error
}

// Проверить версию C++ в коде
void test9()
{

    std::cout << "C++ " << __cplusplus << std::endl;

#if __cplusplus == 202602L // ?
    std::cout << "It's C++26" << std::endl;
#elif __cplusplus == 202100
    std::cout << "It's C++23" << std::endl;
#elif __cplusplus == 202002L
    std::cout << "It's C++20" << std::endl;
#elif __cplusplus == 201703L
    std::cout << "It's C++17" << std::endl;
#elif __cplusplus == 201402L
    std::cout << "It's C++14" << std::endl;
#elif __cplusplus == 201103L
    std::cout << "It's C++11" << std::endl;
#else
    std::cout << "It's C++" << std::endl;
#endif
}

// Бесконечный цикл
void test10()
{
    FOREVER
    {
        break;
    }
}

} // namespace Example3
