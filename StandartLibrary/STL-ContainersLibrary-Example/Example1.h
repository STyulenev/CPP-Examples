#pragma once

#include <algorithm>

#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>

#include "SomeClass.h"

/*
 * =======================================================================================================================================================================
 *                                                                      Sequence
 * =======================================================================================================================================================================
 *
 * - array
 * - vector
 * - forward_list
 * - list
 * - deque
 *
 */

namespace Example1 {

namespace Array {
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

    printContainer(array.begin(), array.end());

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

void test()
{
    test_1();
    test_2();
}

} // namespace Array





namespace Vector {

/*
 * 1) std::vector — это контейнер последовательностей, инкапсулирующий динамические массивы размера.
 * 2) std::pmr::vector — это шаблон псевдонима, использующий полиморфный распределитель. Элементы хранятся непрерывно, что означает, что к
 * элементам можно получить доступ не только через итераторы, но и с помощью смещений к обычным указателям на элементы. Это означает, что указатель на
 * элемент вектора может быть передан любой функции, которая ожидает указатель на элемент массива.
 *
 * Хранение вектора обрабатывается автоматически, расширяясь по мере необходимости. Векторы обычно занимают больше места, чем статические массивы, потому что больше
 * памяти выделяется для обработки будущего роста. Таким образом, вектору не нужно перераспределяться каждый раз при вставке элемента, а только когда
 * дополнительная память исчерпана. Общий объем выделенной памяти можно запросить с помощью функции capacity(). Дополнительная память может быть возвращена в
 * систему с помощью вызова shrink_to_fit().
 *
 * Перераспределения обычно являются затратными операциями с точки зрения производительности. Функция reserve() может быть использована для устранения
 * перераспределений, если количество элементов известно заранее.
 *
 * Реализация - динамический массив
 *
 * Временная сложность:
 * - Вставка в начало - n/a (нет метода push_front())
 * - Вставка в конец - O(1) (если size < capacity, иначе O(n) при перезаписи)
 * - Вставка в середину - O(n) (сдвиг всех правых или перезапись)
 *
 * - Удаление элементов в начале - n/a (нет pop_front()), O(1) при std::swap с последним + pop_back()
 * - Удаление элементов в конце - O(1)
 * - Удаление из середины - O(n) (при remove-erase)
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(log n) (если отсортированы элементы, иначе O(n) при переборе)
*/

void prindData(const std::vector<SomeClass*>& vector)
{
    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
}

void prindData(const std::vector<SomeClass>& vector)
{
    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
}

/*
 * Создание + вставка
 */
void test_1()
{
    // Создали вектор на 5 указателей (пустых)
    std::vector<SomeClass*> vector(5);
    prindData(vector);

    for (auto element : vector) {
        if (element)
            std::cout << element->getField() << std::endl; // error, указатели есть, а объектов нет
    }

    std::vector<SomeClass> v2(5);
    prindData(v2);

    for (auto element : v2) {
        std::cout << element.getField() << std::endl; // ok
    }

    // Утечка
}

/*
 * Проверка размера и ёмкости
 */
void test_2()
{
    std::vector<SomeClass*> vector;
    prindData(vector); // Size: 0 Capacity: 0
    vector.push_back(new SomeClass(1));
    prindData(vector); // Size: 1 Capacity: 1
    vector.push_back(new SomeClass(2));
    prindData(vector); // Size: 2 Capacity: 2
    vector.push_back(new SomeClass(3));
    prindData(vector); // Size: 3 Capacity: 4 (перезапись)
    vector.push_back(new SomeClass(4));
    prindData(vector); // Size: 4 Capacity: 4
    vector.push_back(new SomeClass(5));
    prindData(vector); // Size: 5 Capacity: 8
    vector.push_back(new SomeClass(6));
    prindData(vector); // Size: 6 Capacity: 8

    // Утечка
}

/*
 * Удаление №1, используя цикл с простым счётчиком и std::swap + delete
 */
void test_3()
{
    // swap и pop_back()
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    printContainer(vector);

    for (int index = 0; index < vector.size();) {
        if (vector.at(index)->getField() % 2 == 1) {
            delete vector.at(index); // если удалили элемент, то счётчик не увеличиваем
            std::swap(vector.at(index), vector.back()); // Обмен с последним элементом
            vector.pop_back(); // Удалили последний
        } else {
            ++index; // чтобы не выйти за границу вектора
        }

        prindData(vector);
    }

    printContainer(vector); // В разном порядке из-за swap

    // Утечка
}

/*
 * Удаление №2, используя цикл итераторов + delete, erase
 */
void test_4()
{
    std::vector<SomeClass *> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    prindData(vector);
    printContainer(vector);

    for (auto it = vector.begin(); it != vector.end(); /*++it - error*/) {
        if ((*it)->getField() % 2 == 1) {
            std::cout << "  --->" << (*it)->getField() << " was deleted" << std::endl;
            delete (*it);
            it = vector.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            std::cout << "  --->" << (*it)->getField() << " was missed" << std::endl;
            ++it;
        }
        prindData(vector);
    }

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Удаление №3, используя идиому remove-erase в два шага
 */
void test_5()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));
    prindData(vector);
    printContainer(vector);

    // Не удаляет элементы, а перемещает вначало те, которые надо оставить. Размер не меняется
    auto it = std::remove_if(vector.begin(), vector.end(), [](SomeClass* element) -> bool {
        bool status = (element->getField() % 2 != 1);
        if (status)
            delete element; // тут удаляем объект, но указатель ещё живёт и перемещается в конец
        return status;
    });

    prindData(vector);
    printContainer(vector);

    std::cout << "------ erase" << std::endl;

    // Удаляет ненужные начиная с it
    vector.erase(it, vector.end());

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Удаление №3, используя сокращенную идиому remove-erase
 */
void test_6()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    prindData(vector);
    printContainer(vector);

    vector.erase(std::remove_if(vector.begin(), vector.end(), [](SomeClass* item) {
                     // delete item
                     return item->getField() % 2 != 1;
                 }), // Утечка
                 vector.end());

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Доступ к элементам
 */
void test_7()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));

    // at выбрасывает ошибку при выходе за пределы, [] - нет
    std::cout << "at = " << vector.at(1)->getField() << ", [] = " << vector[1]->getField() << std::endl;

    // v1.data() - возвращает указатель на массив
    std::cout << "First = " << vector.front()->getField()
              << ", Last = " << vector.back()->getField() << " " << vector.data()[2]
              << std::endl;

    // Утечка
}

/*
 * Размер, ёмкость
 */
void test_8()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));

    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Empty = " << (vector.empty() ? "true" : "false") << std::endl;
    std::cout << "Max Size = " << vector.max_size() << std::endl;
    vector.reserve(10); // Увеличили ёмкость
    std::cout << "Capacity = " << vector.capacity() << std::endl;

    // Утечка
}

/*
 * Модификаторы
 */
void test_9()
{
    std::vector<SomeClass> vector;
    vector.emplace_back(1);
    vector.emplace_back(3); // Вызывает конструктор в зависимости от набора элементов
    vector.emplace(vector.end(), 3);

    // вставка на нужную позицию
    auto it = vector.begin();
    it = vector.insert(it, 200);

    // Несколько раз будет перезапись компонентов из-за перезаписи вектора в
    // другую часть памяти

    prindData(vector);
    printContainer(vector);
}

void test()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
}

} // namespace Vector





namespace ForvardList {

/*
 * std::forward_list — это контейнер, который поддерживает быструю вставку и удаление элементов из любого места контейнера. Быстрый произвольный доступ не
 * поддерживается. Он реализован как односвязный список. По сравнению с std::list этот контейнер обеспечивает более эффективное использование пространства, когда
 * двунаправленная итерация не требуется.
 *
 * Добавление, удаление и перемещение элементов в списке или между несколькими списками не делает итераторы, которые в данный момент ссылаются на другие
 * элементы в списке, недействительными. Однако итератор или ссылка, ссылающаяся на элемент, становится недействительной, когда соответствующий элемент удаляется
 * (через erasure_after) из списка.
 *
 * std::forward_list соответствует требованиям Container (за исключением функции-члена size и того, что сложность оператора == всегда линейна),
 * AllocatorAwareContainer и SequenceContainer.
 *
 * Реализация - односвязный список
 *
 * Временная сложность:
 * - Вставка в начало - O(1)
 * - Вставка в конец - n(a)
 * - Вставка в середину - O(1) (без учёта поиска)
 *
 * - Удаление элементов в начале - O(1)
 * - Удаление элементов в конце - n(a)
 * - Удаление из середины - O(1) (без учёта поиска)
 *
 * - Поиск по индексу - n/a (нет методов .at() и operator[])
 * - Поиск - O(n) (всегда перебором)
*/

/*
 * Проверка создания
 */
void test_1()
{
    std::forward_list<SomeClass*> forward_list;

    forward_list.push_front(new SomeClass(2));
    forward_list.push_front(new SomeClass(3));
    forward_list.push_front(new SomeClass(1));
    forward_list.push_front(new SomeClass(3));

    // Нет метода size()
    std::cout << "Empty: " << (forward_list.empty() == 0 ? "true" : "false") << " MaxSize: " << forward_list.max_size() << std::endl;

    printContainer(forward_list.begin(), forward_list.end());
}

/*
 * Удаление
 */
void test_2()
{
    std::forward_list<SomeClass*> forward_list;

    forward_list.push_front(new SomeClass(1));
    forward_list.push_front(new SomeClass(2));
    forward_list.push_front(new SomeClass(3));
    forward_list.push_front(new SomeClass(4));
    forward_list.push_front(new SomeClass(5));
    forward_list.push_front(new SomeClass(6));
    forward_list.push_front(new SomeClass(7));

    printContainer(forward_list.begin(), forward_list.end());

    auto prev = forward_list.before_begin(); // Интератор на предыдущий элемент
    for (auto it = forward_list.begin(); it != forward_list.end();) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = forward_list.erase_after(prev); // Итератор "протух", обновили
        } else {
            prev = it;
            ++it;
        }
    }

    printContainer(forward_list.begin(), forward_list.end());
}

/*
 * Удаление через remove_if
 */
void test_3()
{
    std::forward_list<SomeClass*> forward_list;

    forward_list.push_front(new SomeClass(1));
    forward_list.push_front(new SomeClass(2));
    forward_list.push_front(new SomeClass(3));
    forward_list.push_front(new SomeClass(4));
    forward_list.push_front(new SomeClass(5));
    forward_list.push_front(new SomeClass(6));

    printContainer(forward_list.begin(), forward_list.end());

    forward_list.remove_if([](SomeClass* element) -> bool {
        if (element->getField() % 2 == 1) {
            delete element;
            return true;
        } else {
            return false;
        }
    });

    printContainer(forward_list.begin(), forward_list.end());
}

void test()
{

    test_1();
    test_2();
    test_3();
}

} // namespace ForvardList






namespace List {

/*
 * std::list — это контейнер, который поддерживает вставку и удаление элементов из любого места контейнера за постоянное время. Быстрый произвольный доступ не
 * поддерживается. Обычно он реализуется как двусвязный список. По сравнению с std::forward_list этот контейнер обеспечивает возможность двунаправленной
 * итерации, будучи менее эффективным по пространству.
 *
 * Добавление, удаление и перемещение элементов в списке или между несколькими списками не делает итераторы или ссылки недействительными. Итератор становится
 * недействительным только при удалении соответствующего элемента.
 *
 * Реализация - двухсвязный список
 *
 * Временная сложность:
 * - Вставка в начало - O(1)
 * - Вставка в конец - O(1)
 * - Вставка в середину - O(1) (без учёта поиска)
 *
 * - Удаление элементов в начале - O(1)
 * - Удаление элементов в конце - O(1)
 * - Удаление из середины - O(1)
 *
 * - Поиск по индексу - n/a (нет методов .at() и operator[])
 * - Поиск - O(n) (всегда перебором)
 */

void printData(const std::list<SomeClass*>& list)
{
    std::cout << "Size: " << list.size() << std::endl;
}

/*
 * Проверка создания + удаление неуникальных
 */
void test_1()
{
    std::list<SomeClass*> list;

    list.insert(list.begin(), new SomeClass(2));
    list.insert(list.end(), new SomeClass(3));
    list.insert(list.begin(), new SomeClass(1));
    list.insert(list.end(), new SomeClass(3));

    // l1.begin() + 1; нельзя, только ++ или --
    list.insert(list.end(), new SomeClass(4));

    list.resize(8, new SomeClass(5));
    list.push_back(new SomeClass(7));
    list.push_front(new SomeClass(0));

    printData(list);
    printContainer(list);

    // Удаление неуникальных
    list.unique([](SomeClass* lhs, SomeClass* rhs) -> bool {
        return *lhs == *rhs;
    });

    printContainer(list);

    // Утечка
}

/*
 * Удаление элементов
 */
void test_2()
{
    std::list<SomeClass*> list = {
        new SomeClass(0),
        new SomeClass(1),
        new SomeClass(2),
        new SomeClass(3),
        new SomeClass(4),
        new SomeClass(5),
        new SomeClass(6)
    };

    printData(list);
    printContainer(list);

    // Удаление первого и последнего
    {
        auto it = list.end();

        (*it)->~SomeClass();
        list.pop_back(); // Здесь итератор "протух"

        it = list.begin();

        (*it)->~SomeClass();
        list.pop_front(); // Здесь итератор "протух"
    }

    printData(list);
    printContainer(list);

    // Удаление элементов (в цикле) с нечётным значением field
    for (auto it = list.begin(); it != list.end();) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = list.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            ++it;
        }
    }

    printData(list);
    printContainer(list);

    // Утечка
}

void test()
{
    test_1();
    test_2();
}

} // namespace List






namespace Deque {

/*
 * std::deque (двусторонняя очередь) — это индексированный контейнер последовательностей, который позволяет быстро вставлять и удалять как в начале,
 * так и в конце. Кроме того, вставка и удаление в любом конце deque никогда не делает указатели или ссылки на остальные элементы недействительными.
 *
 * В отличие от std::vector, элементы deque не хранятся непрерывно: типичные реализации используют последовательность индивидуально выделенных массивов
 * фиксированного размера с дополнительным учетом, что означает, что индексированный доступ к deque должен выполнять два разыменования указателя, по
 * сравнению с индексированным доступом vector, который выполняет только одно.
 *
 * Хранилище deque автоматически расширяется и сжимается по мере необходимости. Расширение deque дешевле, чем расширение std::vector, поскольку оно не
 * подразумевает копирования существующих элементов в новое место памяти. С другой стороны, deques обычно имеют большую минимальную стоимость памяти; deque,
 * содержащий только один элемент, должен выделить весь свой внутренний массив (например, 8-кратный размер объекта в 64-битной libstdc++; 16-кратный размер
 * объекта или 4096 байт, в зависимости от того, что больше, в 64-битной libc++).
 *
 * Реализация - двухсвязный список массивов ([][][0][1] <=> [2][3][4][5] <=> [6][7][][] ..., где [][][][] это страница
 *
 * Временная сложность:
 * - Вставка в начало - O(1)
 * - Вставка в конец - O(1)
 * - Вставка в середину - O(1) если пустой, O(n/2) если полный (сдвиг половины элементов)
 *
 * - Удаление элементов в начале - O(1)
 * - Удаление элементов в конце - O(1)
 * - Удаление из середины - O(n/2)
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(n) (перебором)
*/

void printData(const std::deque<SomeClass*>& deque)
{
    std::cout << "Size: " << deque.size() << std::endl;
}

/*
 * Проверка создания + вставка
 */
void test_1()
{
    std::deque<SomeClass*> deque;

    deque.insert(deque.begin(), new SomeClass(2));
    deque.insert(deque.end(), new SomeClass(3));
    deque.insert(deque.begin(), new SomeClass(1));
    deque.insert(deque.end(), new SomeClass(3));

    deque.insert(deque.begin() + 2, new SomeClass(20));

    deque.resize(8, new SomeClass(5));
    deque.push_back(new SomeClass(7));
    deque.push_front(new SomeClass(0));

    printData(deque);
    printContainer(deque);

    // Утечка
}

void test()
{
    test_1();
    // ...
}

} // namespace Deque

} // namespace Example1
