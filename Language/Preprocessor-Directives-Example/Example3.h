#pragma once

#include <iostream>

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

void test4()
{
    MESSAGE(This is log)
}

void test5()
{
    std::cout << DIDGITALSUM(2, 5) << std::endl;
}

} // namespace Example3
