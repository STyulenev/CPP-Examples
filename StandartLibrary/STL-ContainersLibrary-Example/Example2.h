#pragma once

#include <algorithm>

#include <set>
#include <map>

#include <string>

#include "SomeClass.h"

/*
 * =======================================================================================================================================================================
 *                                                                      Associative
 * =======================================================================================================================================================================
 *
 * - set
 * - map
 * - multi_set
 * - multi_map
 *
 */

namespace Example2 {

namespace Set {

/*
 * Множество (std::set) представляет такой контейнер, который может хранить только уникальные значения. Как правило, множества применяются для создания коллекций,
 * которые не должны иметь дубликатов.
 *
 * Реализация - красно-чёрное дерево (самобалансирующаяся структура данных двоичного дерева поиска)
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка O(1), O(n) в худшем случае
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, просто удаление O(log n) т.к. идёт балансирование
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(log n)
 *
 * Характеристики
 * - Элементы отсортированы.
 * - Все элементы уникальные.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::set<SomeClass*>& set)
{
    std::cout << "Empty: " << std::boolalpha << set.empty() << " Size: " << set.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::set<SomeClass*> set;
    set.insert(new SomeClass(5));
    set.insert(new SomeClass(4));
    set.insert(new SomeClass(2));

    printData(set);
    printContainer(set);

    // Утечка
}

/*
 * Удаление по условию
 */
void test_2()
{
    std::set<SomeClass*> set;

    set.insert(new SomeClass(5));
    set.insert(new SomeClass(4));
    set.insert(new SomeClass(2));
    set.insert(new SomeClass(1));
    set.insert(new SomeClass(3));

    printContainer(set);

    for (auto it = set.begin(); it != set.end(); ) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = set.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            ++it;
        }
    }

    printContainer(set);

    // Утечка
}

/*
 * Поиск/проверка вхождения
 */
void test_3()
{
    std::set<SomeClass*> set;

    SomeClass* zeroElement = nullptr;
    SomeClass* secondElement = new SomeClass(4);
    set.insert(new SomeClass(5));
    set.insert(secondElement);
    set.insert(new SomeClass(2));

    secondElement->setField(44);

    printContainer(set);

    std::cout << "There is new SomeClass(4): " << (set.count(secondElement) ? "true" : "false") << std::endl;
    std::cout << "There is new SomeClass(nullptr): " << (set.count(zeroElement) ? "true" : "false") << std::endl;
}

void test()
{
    std::cout << "test_1" << std::endl;
    test_1();

    std::cout << std::endl << "test_2" << std::endl;
    test_2();

    std::cout << std::endl << "test_3" << std::endl;
    test_3();
}

} // namespace Set





namespace Map {


/*
 * Карта (std::map) — это сортированный ассоциативный контейнер, содержащий пары ключ-значение с уникальными ключами. Ключи сортируются с помощью
 * функции сравнения Compare.
 *
 * Реализация - красно-чёрное дерево (самобалансирующаяся структура данных двоичного дерева поиска)
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка O(log n) т.к. идёт балансирование
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, просто удаление O(log n) т.к. идёт балансирование
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(log n)
 *
 * Характеристики
 * - Элементы отсортированы (по ключу).
 * - Все элементы уникальные (по ключу).
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::map<std::string, SomeClass*>& map)
{
    std::cout << "Empty: " << std::boolalpha << map.empty() << " Size: " << map.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::map<std::string, SomeClass*> map;
    map.insert({std::string("first"), new SomeClass(5)});
    map.insert({std::string("second"), new SomeClass(4)});
    map.insert({std::string("third"), new SomeClass(2)});
    map.insert({std::string("third"), new SomeClass(8)}); // Не вставилось, ключ уже существует
    map.insert({std::string("fourth"), new SomeClass(34)});

    printData(map);
    printMap(map);

    // Утечка
}

/*
 * Поиск по ключу и изменение значения
 */
void test_2()
{
    std::map<std::string, SomeClass*> map;
    map.insert({std::string("first"), new SomeClass(5)});
    map.insert({std::string("second"), new SomeClass(4)});
    map.insert({std::string("third"), new SomeClass(2)});

    printData(map);
    printMap(map);

    std::map<std::string, SomeClass*>::iterator it = map.find("third");
    if (it != map.end())
        it->second->setField(45);

    printData(map);
    printMap(map);

    // Утечка
}

/*
 * Удаление элементов по нечётному значению
 */
void test_3()
{
    std::map<std::string, SomeClass*> map;
    map.insert({std::string("first"), new SomeClass(5)});
    map.insert({std::string("second"), new SomeClass(4)});
    map.insert({std::string("third"), new SomeClass(2)});
    map.insert({std::string("fourth"), new SomeClass(7)});

    printData(map);
    printMap(map);

    for (auto it = map.begin(); it != map.end();) {
        if (it->second->getField() % 2 != 0) {
            delete (it->second);
            it = map.erase(it);
        } else {
            ++it;
        }
    }

    printData(map);
    printMap(map);

    // Утечка
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace Map






namespace MultiSet {

/*
 * Множество (std::multiset) представляет собой std::set, который может хранить повторяющиеся значения.
 *
 * Реализация - красно-чёрное дерево (самобалансирующаяся структура данных двоичного дерева поиска)
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка O(log n) т.к. идёт балансирование
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, просто удаление O(log n) т.к. идёт балансирование
 *
 * - Поиск по индексу - O(1), до O(n) если есть одинаковые
 * - Поиск - O(log n), O(n) если несколько одинаковых
 *
 * Характеристики
 * - Элементы отсортированы.
 * - Элементы могут повторятся.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::multiset<SomeClass*>& multiset)
{
    std::cout << "Empty: " << std::boolalpha << multiset.empty() << " Size: " << multiset.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::multiset<SomeClass*> multiset;
    multiset.insert(new SomeClass(5));
    multiset.insert(new SomeClass(4));
    multiset.insert(new SomeClass(2));
    multiset.insert(new SomeClass(4));

    printData(multiset);
    printContainer(multiset);

    // Утечка
}

/*
 * Удаление по условию
 */
void test_2()
{
    std::multiset<SomeClass*> multiset;

    multiset.insert(new SomeClass(5));
    multiset.insert(new SomeClass(4));
    multiset.insert(new SomeClass(2));
    multiset.insert(new SomeClass(1));
    multiset.insert(new SomeClass(3));

    printContainer(multiset);

    for (auto it = multiset.begin(); it != multiset.end(); ) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = multiset.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            ++it;
        }
    }

    printContainer(multiset);

    // Утечка
}

/*
 * Поиск/проверка вхождения
 */
void test_3()
{
    std::multiset<SomeClass*> multiset;

    SomeClass* zeroElement = nullptr;
    SomeClass* secondElement = new SomeClass(4);
    multiset.insert(new SomeClass(5));
    multiset.insert(secondElement);
    multiset.insert(new SomeClass(2));

    secondElement->setField(44);

    printContainer(multiset);

    std::cout << "There is new SomeClass(4): " << (multiset.count(secondElement) ? "true" : "false") << std::endl;
    std::cout << "There is new SomeClass(nullptr): " << (multiset.count(zeroElement) ? "true" : "false") << std::endl;
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace MultiSet





namespace MultiMap {


/*
 * Карта (std::multimap) — представляет собой std::map, который может хранить повторяющиеся значения.
 *
 * Реализация - красно-чёрное дерево (самобалансирующаяся структура данных двоичного дерева поиска)
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка O(log n) т.к. идёт балансирование
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, просто удаление O(log n) т.к. идёт балансирование
 *
 * - Поиск по индексу - O(1), до O(n) если есть одинаковые
 * - Поиск - O(log n), O(n) если несколько одинаковых
 *
 * Характеристики
 * - Элементы отсортированы (по ключу).
 * - Элементы могут быть не уникальными.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::multimap<std::string, SomeClass*>& multimap)
{
    std::cout << "Empty: " << std::boolalpha << multimap.empty() << " Size: " << multimap.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::multimap<std::string, SomeClass*> multimap;
    multimap.insert({std::string("first"), new SomeClass(5)});
    multimap.insert({std::string("second"), new SomeClass(4)});
    multimap.insert({std::string("third"), new SomeClass(2)});
    multimap.insert({std::string("third"), new SomeClass(8)});
    multimap.insert({std::string("fourth"), new SomeClass(34)});

    printData(multimap);
    printMap(multimap);

    // Утечка
}

/*
 * Поиск по ключу и изменение значения
 */
void test_2()
{
    std::multimap<std::string, SomeClass*> multimap;
    multimap.insert({std::string("first"), new SomeClass(5)});
    multimap.insert({std::string("second"), new SomeClass(4)});
    multimap.insert({std::string("third"), new SomeClass(2)});

    printData(multimap);
    printMap(multimap);

    std::multimap<std::string, SomeClass*>::iterator it = multimap.find("third");
    if (it != multimap.end())
        it->second->setField(45);

    printData(multimap);
    printMap(multimap);

    // Утечка
}

/*
 * Удаление элементов по нечётному значению
 */
void test_3()
{
    std::multimap<std::string, SomeClass*> multimap;
    multimap.insert({std::string("first"), new SomeClass(5)});
    multimap.insert({std::string("second"), new SomeClass(4)});
    multimap.insert({std::string("third"), new SomeClass(2)});
    multimap.insert({std::string("fourth"), new SomeClass(7)});

    printData(multimap);
    printMap(multimap);

    for (auto it = multimap.begin(); it != multimap.end();) {
        if (it->second->getField() % 2 != 0) {
            delete (it->second);
            it = multimap.erase(it);
        } else {
            ++it;
        }
    }

    printData(multimap);
    printMap(multimap);

    // Утечка
}

void test()
{
    test_1();
    test_2();
    test_3();
}


} // namespace MultiMap

} // namespace Example2
