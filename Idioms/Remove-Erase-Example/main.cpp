#include <algorithm>
#include <iostream>

#include "SomeClass.h"

/*
 * Remove-erase idiom в C++ — это подход к удалению элементов из контейнера, который предполагает применение алгоритма remove() или
 * remove_if(), за которым следует вызов функции erase() контейнера.
 *
 * При использовании алгоритмов remove() и remove_if() элементы, которые нужно сохранить, помещаются в начало контейнера, а функции
 * возвращают итератор на первый удаляемый элемент. Затем этот итератор передаётся в функцию erase(), которая и удаляет элементы.
 *
 * Этот подход обычно эффективен, так как для большинства типов контейнеров перемещение нежелательных элементов в конец контейнера, а
 * затем удаление их всех за одну операцию erase(). Это особенно эффективно при работе с массивами, таких как std::vector.
 */

int main()
{
    std::cout << "Example 1:" << std::endl;

    { // Удаление чётных элементов вектора через итератор + erase
        std::vector<SomeClass*> v;
        v.push_back(new SomeClass(1));
        v.push_back(new SomeClass(2));
        v.push_back(new SomeClass(3));
        v.push_back(new SomeClass(4));
        v.push_back(new SomeClass(5));

        prindSizeNCapacity(v);
        printVector(v);

        for (auto it = v.begin(); it != v.end();) {
            if ((*it)->getField() % 2 != 1) {
                delete *it;
                it = v.erase(it);
            } else {
                ++it;
            }
        }

        prindSizeNCapacity(v);
        printVector(v);

        // P.S. утечка памяти от оставшихся элементов
    }

    std::cout << std::endl << "Example 2:" << std::endl;

    { // Удаление чётных элементов вектора через remove + erase
        std::vector<SomeClass*> v;
        v.push_back(new SomeClass(1));
        v.push_back(new SomeClass(2));
        v.push_back(new SomeClass(3));
        v.push_back(new SomeClass(4));
        v.push_back(new SomeClass(5));

        prindSizeNCapacity(v);
        printVector(v);

        std::cout << "----- remove_if" << std::endl;

        // Не удаляет элементы, а перемещает в конец те, которые надо удалить и возвратит итератор на первый удаляемый элемент.
        // Размер не меняется
        auto it = std::remove_if(v.begin(), v.end(), [](SomeClass* item) -> bool {
            bool status = (item->getField() % 2 != 1);
            if (status)
                delete item; // тут удаляем объект, но указатель ещё живёт и перемещается в конец
            return status;
        });
        prindSizeNCapacity(v);
        printVector(v); // может быть ошибка, т.к. был delete и память может быть переиспользована

        std::cout << "----- erase" << std::endl;

        // Удаляет окончательно начиная с it до v.end()
        v.erase(it, v.end());
        prindSizeNCapacity(v);
        printVector(v);

        // P.S. утечка памяти от оставшихся элементов
    }

    std::cout << std::endl << "Example 3:" << std::endl;

    { // Сокращённый вариант remove + erase
        std::vector<SomeClass*> v;
        v.push_back(new SomeClass(1));
        v.push_back(new SomeClass(2));
        v.push_back(new SomeClass(3));
        v.push_back(new SomeClass(4));
        v.push_back(new SomeClass(5));

        prindSizeNCapacity(v);
        printVector(v);
        v.erase(std::remove_if(v.begin(), v.end(),
                                [](SomeClass* item) {
                                    if (item->getField() % 2 != 1) {
                                        delete item;
                                        return true;
                                    } else
                                        return false;
                                }),
                 v.end());
        prindSizeNCapacity(v);
        printVector(v);

        // P.S. утечка памяти от оставшихся элементов
    }

    std::cout << std::endl << "Example 4:" << std::endl;

    { // std::erase_if из C++20
        std::vector<SomeClass*> v;
        v.push_back(new SomeClass(1));
        v.push_back(new SomeClass(2));
        v.push_back(new SomeClass(3));
        v.push_back(new SomeClass(4));
        v.push_back(new SomeClass(5));

        prindSizeNCapacity(v);
        printVector(v);

        std::erase_if(v, [](SomeClass* item) {
            if (item->getField() % 2 != 1) {
                delete item;
                return true;
            } else
                return false;
        });

        prindSizeNCapacity(v);
        printVector(v);

        // P.S. утечка памяти от оставшихся элементов
    }

    return 0;
}
