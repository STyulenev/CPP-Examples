#include <algorithm>
#include <vector>

#include "SomeClass.h"

/*
 * 1) std::vector — это контейнер последовательностей, инкапсулирующий динамические массивы размера.
 * 2) std::pmr::vector — это шаблон псевдонима, использующий полиморфный распределитель. Элементы хранятся непрерывно, что означает, что к
 * элементам можно получить доступ не только через итераторы, но и с помощью смещений к обычным указателям на элементы. Это означает, что указатель на
 * элемент вектора может быть передан любой функции, которая ожидает указатель на элемент массива.
 *
 * Хранение вектора обрабатывается автоматически, расширяясь по мере необходимости. Векторы обычно занимают больше места, чем статические массивы, потому что больше
 * памяти выделяется для обработки будущего роста. Таким образом, вектору не нужно перераспределяться каждый раз при вставке элемента, а только когда
 * дополнительная память исчерпана. Общий объем выделенной памяти можно запросить с помощью функции capacity(). Дополнительная память может быть возвращена в
 * систему с помощью вызова shrink_to_fit().
 *
 * Перераспределения обычно являются затратными операциями с точки зрения производительности. Функция reserve() может быть использована для устранения
 * перераспределений, если количество элементов известно заранее.
 *
 * Реализация - динамический массив
 *
 * Временная сложность:
 * - Вставка в начало - n/a (нет метода push_front())
 * - Вставка в конец - O(1) (если size < capacity, иначе O(n) при перезаписи)
 * - Вставка в середину - O(n) (сдвиг всех правых или перезапись)
 *
 * - Удаление элементов в начале - n/a (нет pop_front()), O(1) при std::swap с последним + pop_back()
 * - Удаление элементов в конце - O(1)
 * - Удаление из середины - O(n) (при remove-erase)
 *
 * - Поиск по индексу - O(1)
 * - Поиск - O(log n) (если отсортированы элементы, иначе O(n) при переборе)
*/

void prindData(const std::vector<SomeClass*>& vector)
{
    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
}

void prindData(const std::vector<SomeClass>& vector)
{
    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
}

/*
 * Создание + вставка
 */
void test_1()
{
    // Создали вектор на 5 указателей (пустых)
    std::vector<SomeClass*> vector(5);
    prindData(vector);

    for (auto element : vector) {
        if (element)
            std::cout << element->getField() << std::endl; // error, указатели есть, а объектов нет
    }

    std::vector<SomeClass> v2(5);
    prindData(v2);

    for (auto element : v2) {
        std::cout << element.getField() << std::endl; // ok
    }

    // Утечка
}

/*
 * Проверка размера и ёмкости
 */
void test_2()
{
    std::vector<SomeClass*> vector;
    prindData(vector); // Size: 0 Capacity: 0
    vector.push_back(new SomeClass(1));
    prindData(vector); // Size: 1 Capacity: 1
    vector.push_back(new SomeClass(2));
    prindData(vector); // Size: 2 Capacity: 2
    vector.push_back(new SomeClass(3));
    prindData(vector); // Size: 3 Capacity: 4 (перезапись)
    vector.push_back(new SomeClass(4));
    prindData(vector); // Size: 4 Capacity: 4
    vector.push_back(new SomeClass(5));
    prindData(vector); // Size: 5 Capacity: 8
    vector.push_back(new SomeClass(6));
    prindData(vector); // Size: 6 Capacity: 8

    // Утечка
}

/*
 * Удаление №1, используя цикл с простым счётчиком и std::swap + delete
 */
void test_3()
{
    // swap и pop_back()
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    printContainer(vector);

    for (int index = 0; index < vector.size();) {
        if (vector.at(index)->getField() % 2 == 1) {
            delete vector.at(index); // если удалили элемент, то счётчик не увеличиваем
            std::swap(vector.at(index), vector.back()); // Обмен с последним элементом
            vector.pop_back(); // Удалили последний
        } else {
            ++index; // чтобы не выйти за границу вектора
        }

        prindData(vector);
    }

    printContainer(vector); // В разном порядке из-за swap

    // Утечка
}

/*
 * Удаление №2, используя цикл итераторов + delete, erase
 */
void test_4()
{
    std::vector<SomeClass *> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    prindData(vector);
    printContainer(vector);

    for (auto it = vector.begin(); it != vector.end(); /*++it - error*/) {
        if ((*it)->getField() % 2 == 1) {
            std::cout << "  --->" << (*it)->getField() << " was deleted" << std::endl;
            delete (*it);
            it = vector.erase(it); // Здесь итератор "протух", поэтому присвоили новый от erase
        } else {
            std::cout << "  --->" << (*it)->getField() << " was missed" << std::endl;
            ++it;
        }
        prindData(vector);
    }

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Удаление №3, используя идиому remove-erase в два шага
 */
void test_5()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));
    prindData(vector);
    printContainer(vector);

    // Не удаляет элементы, а перемещает вначало те, которые надо оставить. Размер не меняется
    auto it = std::remove_if(vector.begin(), vector.end(), [](SomeClass* element) -> bool {
            bool status = (element->getField() % 2 != 1);
            if (status)
                delete element; // тут удаляем объект, но указатель ещё живёт и перемещается в конец
            return status;
    });

    prindData(vector);
    printContainer(vector);

    std::cout << "------ erase" << std::endl;

    // Удаляет ненужные начиная с it
    vector.erase(it, vector.end());

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Удаление №3, используя сокращенную идиому remove-erase
 */
void test_6()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));
    vector.push_back(new SomeClass(4));
    vector.push_back(new SomeClass(5));

    prindData(vector);
    printContainer(vector);

    vector.erase(std::remove_if(vector.begin(), vector.end(), [](SomeClass* item) {
                     // delete item
                     return item->getField() % 2 != 1;
                 }), // Утечка
            vector.end());

    prindData(vector);
    printContainer(vector);

    // Утечка
}

/*
 * Доступ к элементам
 */
void test_7()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));

    // at выбрасывает ошибку при выходе за пределы, [] - нет
    std::cout << "at = " << vector.at(1)->getField() << ", [] = " << vector[1]->getField() << std::endl;

    // v1.data() - возвращает указатель на массив
    std::cout << "First = " << vector.front()->getField()
              << ", Last = " << vector.back()->getField() << " " << vector.data()[2]
              << std::endl;

    // Утечка
}

/*
 * Размер, ёмкость
 */
void test_8()
{
    std::vector<SomeClass*> vector;
    vector.push_back(new SomeClass(1));
    vector.push_back(new SomeClass(2));
    vector.push_back(new SomeClass(3));

    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Empty = " << (vector.empty() ? "true" : "false") << std::endl;
    std::cout << "Max Size = " << vector.max_size() << std::endl;
    vector.reserve(10); // Увеличили ёмкость
    std::cout << "Capacity = " << vector.capacity() << std::endl;

    // Утечка
}

/*
 * Модификаторы
 */
void test_9()
{
    std::vector<SomeClass> vector;
    vector.emplace_back(1);
    vector.emplace_back(3); // Вызывает конструктор в зависимости от набора элементов
    vector.emplace(vector.end(), 3);

    // вставка на нужную позицию
    auto it = vector.begin();
    it = vector.insert(it, 200);

    // Несколько раз будет перезапись компонентов из-за перезаписи вектора в
    // другую часть памяти

    prindData(vector);
    printContainer(vector);
}

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();

    return 0;
}
