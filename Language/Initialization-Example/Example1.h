#pragma once

#include <iostream>
#include <vector>

/*
 * Виды инициализаций:
 * - Инициализация по умолчанию (Си, default initialization)
 * - Копирующая инициализация (Си, copy initialization)
 * - Агрегатная инициализация (Си, aggregate initialization)
 * - Статическая инициализация (Си, static initialization)
 * - Прямая инициализация (С++98, direct initialization)
 * - Инициализация значением (C++03, value initialization)
 * - Универсальная инициализация (C++11, uniform или unicorn initialization)
 * - Назначенная инициализация (С++20, designated initialization)
 */

namespace Example1 {

// Глобальные переменные инициализируются нулём
int global; // == 0

/*
 * Инициализация по умолчанию (Си). На самом деле никакого значения по умолчанию нет, а лишь то,
 * что осталось в ячейке памяти от предыдущей работы программы/процесса.
 */
void init_1()
{
    std::cout << std::endl;

    { // Стандартный тип
        int i;
        std::cout << __FUNCTION__ << ": i = " << i << std::endl; // undefined behaviour
    }

    { // Структура
        struct SomeStruct {
            int i;
            int j;
        };

        SomeStruct someStruct;
        std::cout << __FUNCTION__ << ": someStruct.i = " << someStruct.i << std::endl; // undefined behaviour
        std::cout << __FUNCTION__ << ": someStruct.j = " << someStruct.j << std::endl; // undefined behaviour
    }

    { // Класс
        class SomeClass {
        public:
            SomeClass() {} // Без member initialiser list (: i(0), j(0))
            // SomeClass(int i, int j) { this->i = i; this->j = j; }
            int getI() const noexcept { return i; }
            int getJ() const noexcept { return j; }

        private:
            int i; // Без default member initialisers (= 0)
            int j; // Без default member initialisers (= 0)
        };

        SomeClass someClass; // Без direct member initializers (SomeClass someClass(1, 2);)
        std::cout << __FUNCTION__ << ": someClass.i = " << someClass.getI() << std::endl; // undefined behaviour
        std::cout << __FUNCTION__ << ": someClass.j = " << someClass.getJ() << std::endl; // undefined behaviour
    }
}

/*
 * Копирующая инициализация (Си). Данная инициализация происходит через знак равенства (=).
 */
void init_2()
{
    std::cout << std::endl;

    { // Стандартный тип
        int i = 2;
        std::cout << __FUNCTION__ << ": i = " << i << std::endl;
    }

    { // Структура/Класс
        struct SomeStruct {
            int i;

            SomeStruct(int i) { this->i = i; }
        };

        // Если нет explicit и тип не совпадает, то произойдёт преобразование типа
        SomeStruct someStruct = 2.5;
        std::cout << __FUNCTION__ << ": someStruct.i = " << someStruct.i << std::endl;
    }
}

/*
 * Агрегатная инициализация (Си). Данная инициализация происходит при инициализации массива
 * с помощью фигурных скобок (= {1, 2, ... };). Так же если класс/структура агрегатная (т.е. все
 * поля публичные), то сработает агрегатная инициализация.
 */
void init_3()
{
    std::cout << std::endl;

    { // Стандартный тип
        int array1[4] = { 0, 1, 2, 3 }; // Размер задан
        int array2[] =  { 0, 1, 2, 3 }; // Автоматическое выведение размера (array size deduction)
    }

    { // Структура/Класс
        struct SomeStruct {
            int i;
            int j;
        };

        SomeStruct someStruct1 = { 1, 2 };
        std::cout << __FUNCTION__ << ": someStruct1.i = " << someStruct1.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct1.j = " << someStruct1.j << std::endl;

        SomeStruct someStruct2 { 1, 2 }; // Можно без =
        std::cout << __FUNCTION__ << ": someStruct2.i = " << someStruct2.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct2.j = " << someStruct2.j << std::endl;
    }
}

/*
 * Статическая инициализация (Си). Статическая переменная инициализируется константой или нулём.
 */
void init_4()
{
    std::cout << std::endl;

    static int i = 3;   // Инициализация константой
    static int j;       // Инициализация нулем

    std::cout << __FUNCTION__ << ": i = " << i << std::endl;
    std::cout << __FUNCTION__ << ": j = " << j << std::endl;
}

/*
 * Прямая инициализация (С++98). Инициализация происходит через конструктор с помощью круглых
 * скобок (...).
 */
void init_5()
{
    std::cout << std::endl;

    { // Стандартный тип
        int i = int(2);
        std::cout << __FUNCTION__ << ": i = " << i << std::endl;

        int j(2);
        std::cout << __FUNCTION__ << ": j = " << j << std::endl;
    }

    { // Структура/Класс
        struct SomeStruct {
            int i;
            int j;

            SomeStruct(int i, int j) { this->i = i; this->j = j; }
        };

        SomeStruct someStruct1 = SomeStruct(1, 2);
        std::cout << __FUNCTION__ << ": someStruct1.i = " << someStruct1.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct1.j = " << someStruct1.j << std::endl;

        SomeStruct someStruct2(1, 2);
        std::cout << __FUNCTION__ << ": someStruct2.i = " << someStruct2.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct2.j = " << someStruct2.j << std::endl;
    }
}

/*
 * Инициализация значением (C++03). Если существует определённый пользователем конструктор по умолчанию,
 * инициализация значением вызывает этот конструктор, в противном случае возвращается нуль.
 */
void init_6()
{
    std::cout << std::endl;

    { // Стандартный тип
        int i = int(); /* или = []() -> int {
            return int(); // value initialization
        }();*/

        // UB в C++98, 0 начиная с C++03
        std::cout << __FUNCTION__ << ": i = " << i << std::endl;
    }

    { // Структура/Класс
        struct SomeStruct {
            int i;
            int j;

            SomeStruct() = default; // Нули
            //SomeStruct() {}       // UB
        };

        // Получение значение из функции
        SomeStruct someStruct = SomeStruct(); /* или = []() -> SomeStruct {
            return SomeStruct(); // value initialization
        }();*/

        std::cout << __FUNCTION__ << ": someStruct.i = " << someStruct.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct.j = " << someStruct.j << std::endl;
    }
}

/*
 * Универсальная инициализация (C++11). Если существует определённый пользователем конструктор по умолчанию,
 * инициализация значением вызывает этот конструктор, в противном случае возвращается нуль.
 */
void init_7()
{
    std::cout << std::endl;

    { // Стандартный тип
        int i = {0};
        std::cout << __FUNCTION__ << ": i = " << i << std::endl;
    }

    { // Структура/Класс

        std::vector<int> vector2 = {0, 1, 2, 3, 4}; // Конструктор с std::initializer_list

        struct SomeStruct {
            int i;
            int j;
        };

        // SomeStruct someStruct{1, 2}; // direct-list-initialization
        SomeStruct someStruct = {1, 2}; // copy-list-initialization

        std::cout << __FUNCTION__ << ": someStruct.i = " << someStruct.i << std::endl;
        std::cout << __FUNCTION__ << ": someStruct.j = " << someStruct.j << std::endl;
    }
}

/*
 * Назначенная инициализация (С++20).
 */
void init_8()
{
    std::cout << std::endl;

    { // Структура/Класс
        struct SomeStruct {
            int a;
            int b;
            int c;
        };

        struct SomeStruct2 {
            int a;
            SomeStruct someStruct;
        };

        SomeStruct someStruct1{.a = 1, .b = 2, .c = 3};

        std::cout << __FUNCTION__ << ": someStruct1.a = " << someStruct1.a << std::endl;
        std::cout << __FUNCTION__ << ": someStruct1.b = " << someStruct1.b << std::endl;
        std::cout << __FUNCTION__ << ": someStruct1.c = " << someStruct1.c << std::endl;

        SomeStruct2 someStruct2{.a = 1, .someStruct{.a = 1, .b = 2, .c = 3}};

        std::cout << __FUNCTION__ << ": someStruct2.a = " << someStruct2.a << std::endl;
        std::cout << __FUNCTION__ << ": someStruct2.someStruct.a = " << someStruct2.someStruct.a << std::endl;
        std::cout << __FUNCTION__ << ": someStruct2.someStruct.b = " << someStruct2.someStruct.b << std::endl;
        std::cout << __FUNCTION__ << ": someStruct2.someStruct.c = " << someStruct2.someStruct.c << std::endl;
    }

    { // Массив, но только в Си, в C++ это не работает
        //int array1[100] = {[13] = 1, [45] = 1, [79] = 1};
        //int array2[100] = {[13] = 1, [30 ... 40] = 1, [45] = 1, [79] = 1};
    }
}

/*
 * Все способы инициализации int переменной (CppCon 2018: Nicolai Josuttis "The Nightmare of Initialization in C++")
 */
void int_init()
{
    int i1;                 // undefined value
    int i2 = 42;            // note: inits with 42
    int i3(42);             // inits with 42
    int i4 = int();         // inits with 42
    int i5{42};             // inits with 42
    int i6 = {42};          // inits with 42
    int i7{};               // inits with 0
    int i8 = {};            // inits with 0
    auto i9 = 42;           // inits with 42
    auto i10{42};           // C++11: std::initializer_list<int>, C++14: int
    auto i11 = {42};        // inits std::initializer_list<int> with 42
    auto i12 = int{42};     // inits int with 42
    int i13();              // declares a function
    //int i14(7, 9);        // compile-time error
    //int i15 = (7, 9);     // OK, inits int with 9 (comma operator)
    //int i16 = int(7, 9);  // compile-time error
    //int i17(7, 9);        // compile-time error
    auto i18 = (7, 9);      // OK, inits int with 9 (comma operator)
    //auto i19 = int(7, 9); // compile-time error
}

void test()
{
    init_1(); // Си
    init_2(); // Си
    init_3(); // Си
    init_4(); // Си
    init_5(); // C++98
    init_6(); // C++03
    init_7(); // C++11
    init_8(); // C++20

    int_init();

    std::cout << __FUNCTION__ << ": global = " << global << std::endl;
}

} // namespace Example1
