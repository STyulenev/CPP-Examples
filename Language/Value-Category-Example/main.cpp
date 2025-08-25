#include "Example1.h"

/*
 *
 * Классификация value categories:
 * Основные категории:
 * - Lvalue (левый операнд) - имеет имя, адрес, может быть модифицирован
 * - Rvalue (правый операнд) - временные значения, не имеют имени
 *
 * Подкатегории (C++11+):
 * - Xvalue (eXpiring value) - объекты, которые можно перемещать
 * - Prvalue (pure rvalue) - чистые временные значения
 * - Glvalue (generalized lvalue) - lvalue или xvalue
 *
 * Ключевые особенности:
 * - Lvalue: можно взять адрес (&x), можно присваивать
 * - Prvalue: временные значения, литералы, результаты функций
 * - Xvalue: результат std::move(), доступ к члену объекта через rvalue
 * - Rvalue references (&&): могут связываться только с rvalues
 * - Move semantics: используют xvalues для эффективного переноса ресурсов
 *
 */

int main()
{
    Example1::test();

    return 0;
}



