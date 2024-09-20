#include "SomeClass.h"

#include <iostream>

/*
 * Пример RVO (Return Value Optimization) - оптимизация возвращаемого значения. Означает, что компилятору
 * разрешено избегать создания временных объектов для возвращаемых значений, даже если они имеют побочные эффекты.
 * Частный случай Copy Elision для rvalue значения при return.
 *
 */
SomeClass test_1()
{
    return SomeClass();
}

/*
 * RVO не сработало т.к. есть ветвление и именование (см. NRVO-Example)
 */
SomeClass test_2(bool status)
{
    if (status) {
        SomeClass a = SomeClass();
        return a;
    } else {
        SomeClass b = SomeClass();
        return b;
    }
}

int main()
{
    { // В этом случае сработал конструктор и деструктор (всего 2).
        SomeClass someClass = test_1();
    }

    std::cout << std::endl;

    { // В этом случае сработал конструктор, конструктор перемещения и два деструктора (всего 4).
        SomeClass someClass = test_2(true);
    }

    return 0;
}
