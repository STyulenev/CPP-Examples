#include <algorithm>
#include <unordered_map>
#include <string>

#include "SomeClass.h"

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
 * - Элементы отсортированы.
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

int main()
{
    //test_1();
    //test_2();
    test_3();

    return 0;
}
