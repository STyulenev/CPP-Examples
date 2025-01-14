#include <climits>
#include <iostream>

// clang-format off

/*
 * Неопределённое поведение в C++ (undefined behavior, UB) — это поведение, которое может возникать в результате использования ошибочных программных
 * конструкций или некорректных данных, на которые стандарт не налагает никаких требований. Также неопределённое поведение может возникать в ситуациях,
 * не описанных в стандарте явно.
 *
 * Некоторые примеры неопределённого поведения в C++:
 * - обращение по нулевому указателю;
 * - двойная блокировка в одном и том же потоке;
 * - деление на ноль;
 * - чтение неинициализированной памяти.
 *
 * Выделяют два класса неопределённого поведения:
 * - Неопределённое поведение на уровне библиотеки (Library Undefined Behavior) — когда сделано что-то, что не предусматривается конкретной библиотекой
 * (в том числе и стандартной, но не всегда). Например, библиотека gMock не допускает донастраивать mock-объект после начала его использования.
 * - Неопределённое поведение на уровне языка (Language Undefined Behavior) — когда сделано что-то, что фундаментально не определено спецификацией языка
 * программирования. Например, разыменован нулевой указатель.
*/

/*
 * Чтение неинициализированной переменной
 */
void example_1()
{
    std::cout << std::endl;

    int i;
    std::cout << __FUNCTION__ << ": i = " << i << std::endl; // Любое значение, которое осталось в ячейке от другой программы
}

/*
 * Обращение к указателю, после вызова delete
 */
void example_2()
{
    std::cout << std::endl;

    struct SomeStruct {
        int i;
        int j;
    };

    SomeStruct* someStruct = new SomeStruct();

    {
        someStruct->i = 1;
        someStruct->j = 2;

        std::cout << __FUNCTION__ << ": someStruct->i = " << someStruct->i << std::endl; // 1
        std::cout << __FUNCTION__ << ": someStruct->j = " << someStruct->j << std::endl; // 2

        delete someStruct; // Освободили память
    }

    std::cout << __FUNCTION__ << ": someStruct->i = " << someStruct->i << std::endl; // undefined behaviour
    std::cout << __FUNCTION__ << ": someStruct->j = " << someStruct->j << std::endl; // undefined behaviour
}

/*
 * Доступ к памяти за пределами границ массива.
 */
void example_3()
{
    std::cout << std::endl;

    int array[4] = { 0, 1, 2, 3 };

    std::cout << __FUNCTION__ << ": arr[10] = " << array[10] << std::endl;
}

int main()
{
    example_1();
    example_2();
    example_3();

    return 0;
}

// clang-format on
