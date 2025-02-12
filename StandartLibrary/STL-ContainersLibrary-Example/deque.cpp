#include <algorithm>
#include <deque>

#include "SomeClass.h"

/*
 * std::deque (двусторонняя очередь) — это индексированный контейнер последовательностей, который позволяет быстро вставлять и удалять как в начале,
 * так и в конце. Кроме того, вставка и удаление в любом конце deque никогда не делает указатели или ссылки на остальные элементы недействительными.
 *
 * В отличие от std::vector, элементы deque не хранятся непрерывно: типичные реализации используют последовательность индивидуально выделенных массивов
 * фиксированного размера с дополнительным учетом, что означает, что индексированный доступ к deque должен выполнять два разыменования указателя, по
 * сравнению с индексированным доступом vector, который выполняет только одно.
 *
 * Хранилище deque автоматически расширяется и сжимается по мере необходимости. Расширение deque дешевле, чем расширение std::vector, поскольку оно не
 * подразумевает копирования существующих элементов в новое место памяти. С другой стороны, deques обычно имеют большую минимальную стоимость памяти; deque,
 * содержащий только один элемент, должен выделить весь свой внутренний массив (например, 8-кратный размер объекта в 64-битной libstdc++; 16-кратный размер
 * объекта или 4096 байт, в зависимости от того, что больше, в 64-битной libc++).
 *
 * Реализация - двухсвязный список массивов ([][][0][1] <=> [2][3][4][5] <=> [6][7][][] ..., где [][][][] это страница
 *
 * Временная сложность:
 * - Вставка в начало - O(1)
 * - Вставка в конец - O(1)
 * - Вставка в середину - O(1) если пустой, O(n/2) если полный (сдвиг половины элементов)
 *
 * - Удаление элементов в начале - O(1)
 * - Удаление элементов в конце - O(1)
 * - Удаление из середины - O(n/2)
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(n) (перебором)
*/

void printData(const std::deque<SomeClass*>& deque)
{
    std::cout << "Size: " << deque.size() << std::endl;
}

/*
 * Проверка создания + вставка
 */
void test_1()
{
    std::deque<SomeClass*> deque;

    deque.insert(deque.begin(), new SomeClass(2));
    deque.insert(deque.end(), new SomeClass(3));
    deque.insert(deque.begin(), new SomeClass(1));
    deque.insert(deque.end(), new SomeClass(3));

    deque.insert(deque.begin() + 2, new SomeClass(20));

    deque.resize(8, new SomeClass(5));
    deque.push_back(new SomeClass(7));
    deque.push_front(new SomeClass(0));

    printData(deque);
    printContainer(deque);

    // Утечка
}

int main()
{
    test_1();

    return 0;
}
