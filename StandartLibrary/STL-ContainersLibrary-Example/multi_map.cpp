#include <algorithm>
#include <map>
#include <string>

#include "SomeClass.h"

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

int main()
{
    test_1();
    //test_2();
    //test_3();

    return 0;
}
