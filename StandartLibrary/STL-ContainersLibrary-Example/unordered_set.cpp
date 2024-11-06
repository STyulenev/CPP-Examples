#include <algorithm>
#include <unordered_set>

#include "SomeClass.h"

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
 * - Элементы отсортированы.
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

int main()
{
    test_1();
    //test_2();
    //test_3();

    return 0;
}
