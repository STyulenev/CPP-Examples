#include "Attorney.h"
#include "ConcreteClass.h"

/*
 * Идиома "Адвокат-Клиент" (Attorney-Client) позволяет классу точно контролировать объем доступа, которые он предоставляет своим классам-друзьям.
 * Декларация friend в C++ дает полный доступ к внутренним данным класса. Поэтому декларации друзей не одобряются, поскольку они нарушают тщательно
 * продуманную инкапсуляцию. Но Attorney-Client позволяет избежать проблем благодаря посредникам:
 *
 * Метод int main() единственным имеет доступ к закрытым членам класса Attorney, Attorney единственный, кто имеет доступ к закрытым членам класса
 * AbstractBase и его конкретной реализации ConcreteClass.
 */
int main()
{
    ConcreteClass concreteClass;

    // concreteClass.callAction1(concreteClass, 10); // Ошибка
    // concreteClass.callAction2(concreteClass);     // Ошибка

    Attorney::callAction1(concreteClass, 10);
    Attorney::callAction2(concreteClass);

    return 0;
}
