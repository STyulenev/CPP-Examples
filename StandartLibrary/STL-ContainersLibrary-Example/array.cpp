#include <algorithm>
#include <array>

#include "SomeClass.h"

/*
 * std::array в языке программирования C++ представляет собой статический массив фиксированного размера, предоставляющий удобный и безопасный интерфейс для
 * работы с последовательностью элементов. Этот контейнер входит в Standard Template Library (STL) и предоставляет набор методов для управления данными.
 *
 * Основные операции с std::array:
 * Доступ к элементам: Элементы std::array могут быть получены с использованием оператора [] или метода std::array::at().
 * Размер массива: Метод std::array::size() возвращает текущий размер массива.
 * Итерация по массиву: Итерация по массиву может быть выполнена с использованием цикла for и диапазона.
 *
 * Реализация - статический массив
 *
 * Временная сложность:
 * - Вставка в начало - n/a (нет метода push_front()), только перезапись array[0] = ...
 * - Вставка в конец - n/a (нет метода push_back()), только перезапись array[last] = ...
 * - Вставка в середину - n/a, только перезапись array[i] = ...
 *
 * - Удаление элементов в начале - n/a (нет pop_front()), только перезапись array[0] = ...
 * - Удаление элементов в конце - n/a (нет pop_back()), только перезапись array[last] = ...
 * - Удаление из середины - n/a, только перезапись array[i] = ...
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(log n) (если отсортированы элементы, иначе O(n) при переборе)
*/

/*
 * Проверка создания
 */
void test_1()
{
    std::array<SomeClass*, 5> array;

    array[0] = new SomeClass(2);
    array[1] = new SomeClass(3);
    array[2] = new SomeClass(1);
    array[3] = new SomeClass(3);
    array[4] = new SomeClass(3);

    std::cout << "Empty: " << (array.empty() == 0 ? "true" : "false") << " Size: " << array.size() << std::endl;

    printContainer(array);

    // Утечка
}

/*
 * Чтение, перезапись
 */
void test_2()
{
    std::array<SomeClass*, 5> array;

    array[0] = new SomeClass(2);
    array[1] = new SomeClass(3);
    array[2] = new SomeClass(1);
    array[3] = new SomeClass(3);
    array[4] = new SomeClass(3);
    //array[5] = new SomeClass(4); // terminated

    std::cout << array[5] << std::endl; // будет прочитан мусор
    //std::cout << &array.at(5) << std::endl; // std::out_of_range

    std::cout << "array[0] = " << array[0]->getField() << std::endl;
    delete array[0];
    array[0] = new SomeClass(7);
    std::cout << "array[0] = " << array[0]->getField() << std::endl;

    // Утечка
}

int main()
{
    test_1();
    test_2();

    return 0;
}
