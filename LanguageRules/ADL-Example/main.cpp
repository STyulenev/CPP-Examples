#include <iostream>

/*
 * ADL (Argument-dependent lookup, поиск по аргументам) или поиск по Кенигу - набор правил для поиска неквалифицированных имен функций в
 * выражениях вызова функций, включая неявные вызовы функций для перегруженных операторов. Эти имена функций ищутся в пространствах имен их аргументов
 * в дополнение к областям и пространствам имен, рассматриваемым обычным поиском неквалифицированных имен.
 *
 * Поиск, зависящий от аргументов, позволяет использовать операторы, определенные в другом пространстве имен.
 */

namespace N1 {

void print() {
    std::cout << "N1::print()" << std::endl;
};

} // namespace N1

namespace N2 {

class SomeClass {
public:
    int data = 0;
};

void print() {
    std::cout << "N2::print()" << std::endl;
};

void print(N2::SomeClass someClass) {
    std::cout << "N2::print() = " << someClass.data << std::endl;
};

} // namespace N2

namespace N3 {

void print(N2::SomeClass someClass) {
    std::cout << "N3::print() = " << someClass.data << std::endl;
};

} // namespace N3

namespace N4 {

void print() {
    std::cout << "N4::print()" << std::endl;
};

} // namespace N4

int main()
{
    // Функция найдена в namespace N1
    {
        using namespace N1;

        print(); // N1::print()
    }

    // Функция найдена в namespace N1 и namespace N4
    {
        N1::print();
        (N4::print)();
    }

    // Функция не найдена
    {
        // print(); // error: use of undeclared identifier 'print'
    }

    // Функция не найдена т.к. есть несколько кандидатов
    {
        using namespace N1;
        using namespace N2;

        // print(); // error: call to 'print' is ambiguous ...
    }

    // Функция найдена в namespace N2
    {
        N2::SomeClass someClass;
        someClass.data = 10;

        print(someClass); // Можно не указывать N2::
    }

    // Функция найдена в namespace N3
    {
        N2::SomeClass someClass;
        someClass.data = 10;

        (N3::print)(someClass);
    }

    return 0;
}
