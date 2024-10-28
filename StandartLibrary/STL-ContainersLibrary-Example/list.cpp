#include <algorithm>
#include <list>

#include "SomeClass.h"

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

int main()
{
    // test_1();
    test_2();

    return 0;
}
