#pragma once

#include <unordered_set>
#include <unordered_map>

#include "SomeClass.h"

/*
 * =======================================================================================================================================================================
 *                                                                      Unordered associative
 * =======================================================================================================================================================================
 *
 * - unordered_set
 * - unordered_map
 * - unordered_multiset
 * - unordered_multimap
 *
 */

namespace Example3 {

namespace UnorderedSet {

/*
 * Множество (std::unordered_set) представляет собой неупорядоченный std::set с уникальными ключами.
 *
 * Реализация - хэш-таблица
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка от O(1), до O(n) если есть коллизии
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, удаление по ключу отO(1), до O(n) если есть коллизии
 *
 * - Поиск по индексу - от O(1), до O(n) если есть коллизии
 * - Поиск - от O(1), до O(n) если есть коллизии
 *
 * Характеристики
 * - Элементы могут повторятся.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::unordered_set<SomeClass*>& unordered_set)
{
    std::cout << "Empty: " << std::boolalpha << unordered_set.empty() << " Size: " << unordered_set.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::unordered_set<SomeClass*> unordered_set;
    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(new SomeClass(4));
    unordered_set.insert(new SomeClass(2));
    unordered_set.insert(new SomeClass(4));

    printData(unordered_set);
    printContainer(unordered_set);

    // Утечка
}

/*
 * Удаление по условию
 */
void test_2()
{
    std::unordered_set<SomeClass*> unordered_set;

    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(new SomeClass(4));
    unordered_set.insert(new SomeClass(2));
    unordered_set.insert(new SomeClass(1));
    unordered_set.insert(new SomeClass(3));

    printContainer(unordered_set);

    for (auto it = unordered_set.begin(); it != unordered_set.end(); ) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = unordered_set.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            ++it;
        }
    }

    printContainer(unordered_set);

    // Утечка
}

/*
 * Поиск/проверка вхождения
 */
void test_3()
{
    std::unordered_set<SomeClass*> unordered_set;

    SomeClass* zeroElement = nullptr;
    SomeClass* secondElement = new SomeClass(4);
    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(secondElement);
    unordered_set.insert(new SomeClass(2));

    secondElement->setField(44);

    printContainer(unordered_set);

    std::cout << "There is new SomeClass(4): " << (unordered_set.count(secondElement) ? "true" : "false") << std::endl;
    std::cout << "There is new SomeClass(nullptr): " << (unordered_set.count(zeroElement) ? "true" : "false") << std::endl;
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace UnorderedSet






namespace UnorderedMap {

/*
 * Множество (std::unordered_map) представляет собой неупорядоченный std::map с уникальными ключами.
 *
 * Реализация - хэш-таблица
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка от O(1), до O(n) если есть коллизии
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, удаление по ключу отO(1), до O(n) если есть коллизии
 *
 * - Поиск по индексу - от O(1), до O(n) если есть коллизии
 * - Поиск - от O(1), до O(n) если есть коллизии
 *
 * Характеристики
 * - Элементы могут повторятся.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::unordered_map<std::string, SomeClass*>& unordered_map)
{
    std::cout << "Empty: " << std::boolalpha << unordered_map.empty() << " Size: " << unordered_map.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::unordered_map<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});
    unordered_map.insert({std::string("third"), new SomeClass(8)}); // Не вставилось, ключ уже существует
    unordered_map.insert({std::string("fourth"), new SomeClass(34)});

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

/*
 * Поиск по ключу и изменение значения
 */
void test_2()
{
    std::unordered_map<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});

    printData(unordered_map);
    printMap(unordered_map);

    std::unordered_map<std::string, SomeClass*>::iterator it = unordered_map.find("third");
    if (it != unordered_map.end())
        it->second->setField(45);

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

/*
 * Удаление элементов по нечётному значению
 */
void test_3()
{
    std::unordered_map<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});
    unordered_map.insert({std::string("fourth"), new SomeClass(7)});

    printData(unordered_map);
    printMap(unordered_map);

    for (auto it = unordered_map.begin(); it != unordered_map.end();) {
        if (it->second->getField() % 2 != 0) {
            delete (it->second);
            it = unordered_map.erase(it);
        } else {
            ++it;
        }
    }

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace UnorderedMap






namespace UnorderedMultiSet {

/*
 * Множество (std::unordered_multiset) представляет собой std::unordered_set, который может хранить повторяющиеся значения.
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
 * - Поиск - O(log n), O(n) если несколько одинаковых (или коллизии)
 *
 * Характеристики
 * - Элементы могут повторятся.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 *
 * Сложность операции rehash() в unordered_multiset в среднем случае линейная, а в худшем — квадратичная (O(N^2)).
 */

void printData(const std::unordered_multiset<SomeClass*>& unordered_set)
{
    std::cout << "Empty: " << std::boolalpha << unordered_set.empty() << " Size: " << unordered_set.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::unordered_multiset<SomeClass*> unordered_set;
    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(new SomeClass(4));
    unordered_set.insert(new SomeClass(2));
    unordered_set.insert(new SomeClass(4));

    printData(unordered_set);
    printContainer(unordered_set);

    // Утечка
}

/*
 * Удаление по условию
 */
void test_2()
{
    std::unordered_multiset<SomeClass*> unordered_set;

    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(new SomeClass(4));
    unordered_set.insert(new SomeClass(2));
    unordered_set.insert(new SomeClass(3));
    unordered_set.insert(new SomeClass(3));

    printContainer(unordered_set);

    for (auto it = unordered_set.begin(); it != unordered_set.end(); ) {
        if ((*it)->getField() % 2 == 1) {
            delete (*it);
            it = unordered_set.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            ++it;
        }
    }

    printContainer(unordered_set);

    // Утечка
}

/*
 * Поиск/проверка вхождения
 */
void test_3()
{
    std::unordered_multiset<SomeClass*> unordered_set;

    SomeClass* zeroElement = nullptr;
    SomeClass* secondElement = new SomeClass(4);
    unordered_set.insert(new SomeClass(5));
    unordered_set.insert(secondElement);
    unordered_set.insert(new SomeClass(2));

    secondElement->setField(44);

    printContainer(unordered_set);

    std::cout << "There is new SomeClass(4): " << (unordered_set.count(secondElement) ? "true" : "false") << std::endl;
    std::cout << "There is new SomeClass(nullptr): " << (unordered_set.count(zeroElement) ? "true" : "false") << std::endl;
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace UnorderedSet





namespace UnorderedMultiMap {

/*
 * Множество (std::unordered_multimap) представляет собой неупорядоченный std::unordered_map, который может хранить повторяющиеся значения.
 *
 * Реализация - хэш-таблица
 *
 * Временная сложность:
 * - Вставка в начало - n/a
 * - Вставка в конец - n/a
 * - Вставка в середину - n/a, просто вставка от O(1), до O(n) если есть коллизии
 *
 * - Удаление элементов в начале - n/a
 * - Удаление элементов в конце - n/a
 * - Удаление из середины - n/a, удаление по ключу отO(1), до O(n) если есть коллизии
 *
 * - Поиск по индексу - от O(1), до O(n) если есть коллизии
 * - Поиск - от O(1), до O(n) если есть коллизии
 *
 * Характеристики
 * - Элементы могут повторятся.
 * - Элементы неизменяемые (можно удалить элемент и добавить заново, но изменить нельзя.
 * - Для поиска используетя метод двоичного дерева поиска.
 * - Значения в наборе неиндексированы.
 */

void printData(const std::unordered_multimap<std::string, SomeClass*>& unordered_map)
{
    std::cout << "Empty: " << std::boolalpha << unordered_map.empty() << " Size: " << unordered_map.size() << std::endl;
}

/*
 * Создание и вставка
 */
void test_1()
{
    std::unordered_multimap<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});
    unordered_map.insert({std::string("third"), new SomeClass(8)});
    unordered_map.insert({std::string("fourth"), new SomeClass(34)});

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

/*
 * Поиск по ключу и изменение значения
 */
void test_2()
{
    std::unordered_multimap<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});

    printData(unordered_map);
    printMap(unordered_map);

    std::unordered_map<std::string, SomeClass*>::iterator it = unordered_map.find("third");
    if (it != unordered_map.end())
        it->second->setField(45);

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

/*
 * Удаление элементов по нечётному значению
 */
void test_3()
{
    std::unordered_multimap<std::string, SomeClass*> unordered_map;
    unordered_map.insert({std::string("first"), new SomeClass(5)});
    unordered_map.insert({std::string("second"), new SomeClass(4)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});
    unordered_map.insert({std::string("third"), new SomeClass(2)});

    printData(unordered_map);
    printMap(unordered_map);

    for (auto it = unordered_map.begin(); it != unordered_map.end();) {
        if (it->second->getField() % 2 != 0) {
            delete (it->second);
            it = unordered_map.erase(it);
        } else {
            ++it;
        }
    }

    printData(unordered_map);
    printMap(unordered_map);

    // Утечка
}

void test()
{
    test_1();
    test_2();
    test_3();
}

} // namespace UnorderedMultiMap

} // namespace Example3
