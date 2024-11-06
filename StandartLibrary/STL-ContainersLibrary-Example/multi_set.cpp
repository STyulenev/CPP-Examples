#include <algorithm>
#include <set>

#include "SomeClass.h"

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

int main()
{
    test_1();
    //test_2();
    //test_3();

    return 0;
}
