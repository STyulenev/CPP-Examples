#include <algorithm>
#include <set>

#include "SomeClass.h"

/*
 * Множество (std::set) представляет такой контейнер, который может хранить только уникальные значения. Как правило, множества применяются для создания коллекций,
 * которые не должны иметь дубликатов.
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

int main()
{
    std::cout << "test_1" << std::endl;
    test_1();

    std::cout << std::endl << "test_2" << std::endl;
    test_2();

    std::cout << std::endl << "test_3" << std::endl;
    test_3();

    return 0;
}
