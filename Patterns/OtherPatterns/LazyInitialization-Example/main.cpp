#include "SomeClass.h"

/*
 * Lazy loading (ленивая загрузка) или Lazy initialization (ленивая инициализация) в C++ — паттерн проектирования, в котором операции
 * выносятся из конструктора в отдельный метод. Это особенно удобно, когда создание объекта требует больших затрат, и удобнее отложить его
 * как можно позже или даже полностью пропустить. Например, загрузка файла, запуск TCP/UDP сервера и т.д.
 */

int main()
{
    SomeClass someClass;

    std::cout << someClass << std::endl;

    someClass.launch();

    std::cout << someClass << std::endl;

    return 0;
}
