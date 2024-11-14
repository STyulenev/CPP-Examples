#include <algorithm>
#include <forward_list>

#include "SomeClass.h"

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

    printContainer(forward_list);
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

    printContainer(forward_list);

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

    printContainer(forward_list);
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

    printContainer(forward_list);

    forward_list.remove_if([](SomeClass* element) -> bool {
        if (element->getField() % 2 == 1) {
            delete element;
            return true;
        } else {
            return false;
        }
    });
    printContainer(forward_list);
}

int main()
{

    // test_1();
    // test_2();
    test_3();

    return 0;
}
