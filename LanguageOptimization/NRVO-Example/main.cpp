#include "SomeClass.h"

#include <iostream>

/*
 * Пример NRVO (Named Return Value Optimization) - оптимизация именованного возвращаемого значения. Означает, что компилятору
 * разрешено избегать создания временных объектов для возвращаемых значений, даже если они имеют побочные эффекты. Отличается
 * от RVO созданием именованного объекта. Частный случай Copy Elision для lvalue значения при return.
 *
 */
SomeClass test_1()
{
    SomeClass someClass;

    return someClass;
}

/*
 * NRVO не сработало т.к. неизвестно какой экземпляр требуется вернуть
 */
SomeClass test_2(bool status)
{
    SomeClass a, b;

    if (status) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    { // В этом случае сработал конструктор и деструктор (всего 2).
        SomeClass someClass = test_1();
    }

    std::cout << std::endl;

    { // В этом случае сработало два конструктора, конструктор перемещения и три деструктора
      // (всего 6, два метода вызваны неиспользованой переменной).
        SomeClass someClass = test_2(true);
    }

    return 0;
}
