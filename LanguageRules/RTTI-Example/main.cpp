#include "SomeClass.h"

#include <typeinfo>

/*
 * RTTI (Run-time type information) — это механизм в C++, который раскрывает информацию о типе данных объекта во время выполнения и доступен только для классов,
 * имеющих хотя бы одну виртуальную функцию. Он позволяет определить тип объекта во время выполнения программы.
 *
 * Приведение во время выполнения, которое проверяет, что приведение является допустимым, является самым простым подходом для определения типа во время выполнения
 * объекта с использованием указателя или ссылки. Это особенно полезно, когда нам нужно привести указатель из базового класса к производному типу. При работе с
 * иерархией наследования классов обычно требуется приведение объекта. Существует два типа приведения:
 * - Приведение к базовому типу: когда указатель или ссылка на объект производного класса рассматривается как указатель на базовый класс.
 * - Понижение типа: когда указатель или ссылка базового класса преобразуется в указатель производного класса.
 *
 */

int main()
{
    /*
     * Повышающее приведение также называют восходящим (upcast), поскольку мы движемся от корня дерева вниз (корень традиционно находится наверху).
     */
    {
        SomeClass1* someClass = new SomeClass1();
        ISomeClass* iSomeClass = dynamic_cast<ISomeClass*>(someClass);
        AbstractSomeClass* aSomeClass = dynamic_cast<AbstractSomeClass*>(someClass);

        someClass->print();
        iSomeClass->print();
        aSomeClass->print();

        delete someClass;
    }

    std::cout << std::endl;

    /*
     * Повышающее приведение c SomeClass2
     */
    {
        ISomeClass* iSomeClass = new SomeClass2();
        AbstractSomeClass* aSomeClass = dynamic_cast<AbstractSomeClass*>(iSomeClass);
        SomeClass1* someClass1 = dynamic_cast<SomeClass1*>(iSomeClass);
        SomeClass2* someClass2 = dynamic_cast<SomeClass2*>(someClass1);

        iSomeClass->print();
        aSomeClass->print();
        someClass1->print();
        someClass2->print();

        delete someClass1;
    }

    std::cout << std::endl;

    /*
     * Понижающее приведение (downcast).
     */
    {
        SomeClass1* someClass1 = new SomeClass1();
        SomeClass2* someClass2 = dynamic_cast<SomeClass2*>(someClass1);

        // Базовый someClass1 класс ничего не знает о производном someClass2, результатом будет указатель на nullptr.
        if (someClass2 == nullptr) {
            std::cout << "error: dynamic_cast<SomeClass2*>(someClass1);" << std::endl;
        } else {
            someClass1->print();
            someClass2->print();
        }

        delete someClass1;
    }

    std::cout << std::endl;

    /*
     * Понижающее приведение c SomeClass2
     */
    {
        SomeClass1* someClass1 = new SomeClass2();

        auto func = [] (ISomeClass* iSomeClass) -> void {
            SomeClass2* someClass2 = dynamic_cast<SomeClass2*>(iSomeClass);

            // Базовый iSomeClass знает о производном someClass2, результатом будет приведение к SomeClass2.
            if (someClass2 == nullptr) {
                std::cout << "error: dynamic_cast<SomeClass2*>(someClass1);" << std::endl;
            } else {
                someClass2->print();
            }
        };

        func(someClass1);

        delete someClass1;
    }

    std::cout << std::endl;

    /*
     * Проверка типа
     */
    {
        SomeClass1* someClass1 = new SomeClass1();
        SomeClass2* someClass2 = new SomeClass2();
        ISomeClass* iSomeClass = new SomeClass2();
        AbstractSomeClass* aSomeClass = new SomeClass1();

        // Текущий
        std::cout << typeid(someClass1).name() << std::endl;
        std::cout << typeid(someClass2).name() << std::endl;
        std::cout << typeid(iSomeClass).name() << std::endl;
        std::cout << typeid(aSomeClass).name() << std::endl;

        // Базовый
        std::cout << typeid(*someClass1).name() << std::endl;
        std::cout << typeid(*someClass2).name() << std::endl;
        std::cout << typeid(*iSomeClass).name() << std::endl;
        std::cout << typeid(*aSomeClass).name() << std::endl;

        delete someClass1;
        delete someClass2;
        delete iSomeClass;
        delete aSomeClass;
    }

    return 0;
}
