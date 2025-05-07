#include "Example1.h"

/*
 * Лямбда-выражения представляют более краткий компактный синтаксис для определения объектов-функций:
 * [] (параметры) { действия }
 *
 * Каждый раз, когда компилятор встречает лямбда-выражение, он генерирует новый тип класса, который представляет объект-функцию.
 *  Сгенерированный класс упрощенно может выглядеть примерно так:
 *  class __Lambda2354363463
 *  {
 *  public:
 *      auto operator()() /- const, mutable, exception, trailing return ... -/ { /- ... code ... -/ }
 *  };
 *
 *  Для простого случая, без захвата переменных может быть сгенерирована функция вместо класса/структуры.
 *  Сложный случай:
 *  struct __Lambda457345325
 *  {
 *      std::string& _argl; // const, если не mutable
 *      int _arg2;
 *
 *      __Lambda457345325(std::string &arg1, int arg2) : _arg1(arg1), _arg2(arg2)()
 *
 *      auto operator()(double arg3) /- const, mutable, exception, trailing return ... -/ {
 *          /- ... code ... -/
 *      }
 *  };
 *
 *  Вычисление лямбда-выражения приводит к временному prvalue.
 */
int main()
{
    Example1::test1();
    Example1::test2();
    Example1::test3();
    Example1::test4();
    Example1::test5();
    Example1::test6();
    Example1::test7();
    Example1::test8();
    Example1::test9();
    Example1::test10();

    return 0;
}
