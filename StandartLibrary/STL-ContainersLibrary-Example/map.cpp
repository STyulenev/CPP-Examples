#include <algorithm>
#include <map>
#include <string>

#include "SomeClass.h"

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

int main()
{
    //test_1();
    //test_2();
    test_3();

    return 0;
}
