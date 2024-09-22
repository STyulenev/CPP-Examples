#include <iostream>

#include "ConcreteClass1.h"
#include "ConcreteClass2.h"

/*
 * Capability Query (Запрос возможностей) - используется для проверки поддержки интерфейса во время выполнения программы.
 *
 */

int main()
{
    {
        IFirst* concreteClass = new ConcreteClass1();

        if (IFirst* iFirst = dynamic_cast<IFirst*>(concreteClass)) { // Capability Query
            std::cout << "ok" << std::endl;
            iFirst->method_1();
        } else {
            std::cout << "error" << std::endl;
        }

        if (ISecond* iSecond = dynamic_cast<ISecond*>(concreteClass)) { // Capability Query
            std::cout << "ok" << std::endl;
            iSecond->method_2();
        } else {
            std::cout << "error" << std::endl;
        }

        delete concreteClass;
    }

    {
        IFirst* concreteClass = new ConcreteClass2();

        if (IFirst* iFirst = dynamic_cast<IFirst*>(concreteClass)) { // Capability Query
            std::cout << "ok" << std::endl;
            iFirst->method_1();
        } else {
            std::cout << "error" << std::endl;
        }

        if (ISecond* iSecond = dynamic_cast<ISecond*>(concreteClass)) { // Capability Query
            std::cout << "ok" << std::endl;
            iSecond->method_2();
        } else {
            std::cout << "error" << std::endl;
        }

        delete concreteClass;
    }

    return 0;
}
