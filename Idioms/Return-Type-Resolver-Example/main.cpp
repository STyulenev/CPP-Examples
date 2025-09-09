#include <iostream>

#include <list>
#include <set>
#include <vector>

/*
 * Return Type Resolver (разрешитель типа возвращаемого значения) — это идиома в C++, которая позволяет функции определять свой
 * возвращаемый тип на основе контекста вызова. Это достигается с помощью шаблонов и вывода типов.
 *
 * Тип инициализируемой переменной может быть полезной информацией в определённых контекстах. Например, мы хотим инициализировать
 * контейнеры STL случайными числами. Однако мы не знаем точный тип контейнера, ожидаемый пользователем. Это может быть std::list,
 * std::vector или что-то другое, ведущее себя как контейнер STL.
 *
 * Класс getRandomN имеет конструктор и шаблонную функцию оператора преобразования. Для инициализации создаётся временный объект
 * класса getRandomN , который присваивается требуемому классу контейнера. Компилятор C++ пытается преобразовать временный объект
 * в объект класса контейнера. Единственный способ сделать это — использовать оператор преобразования. Оператор преобразования
 * создаётся с типом заполняемого контейнера. Благодаря автоматическому разрешению возвращаемого типа пользователю не нужно указывать
 * его заново. Обратите внимание, что insertвместо него используется функция-член, push_backпоскольку std::set не поддерживает
 * push_back.
 *
 *
*/

class getRandomN
{
    size_t count;

public:
    getRandomN(int n = 1) : count(n) {}

    template <class Container>
    operator Container ()
    {
        Container c;

        for (size_t i = 0; i < count; ++i)
        {
            c.insert(c.end(), rand());
        }

        return c;
    }

    // Специализация для строки
    operator std::string () const
    {
        return std::string("default_string");
    }
};

class TypeResolver
{
public:
    template <typename T>
    operator T() const {
        return T{};
    }

    // Специализация для строки
    operator std::string() const {
        return "default_string";
    }
};

template <typename T>
T create() {
    TypeResolver resolver;

    return resolver;
}

int main()
{
    // Пример для контейнеров
    {
        std::set<int> random_s = getRandomN(10);

        std::vector<int> random_v = getRandomN(10);
        std::list<int> random_l = getRandomN(10);
        std::string random_str = getRandomN();

        for (int s : random_s)
        {
            std::cout << "random_s: " << s << std::endl;
        }

        std::cout << "-------" << std::endl;

        for (int v : random_v)
        {
            std::cout << "random_v: " << v << std::endl;
        }

        std::cout << "-------" << std::endl;

        for (int l : random_l)
        {
            std::cout << "random_l: " << l << std::endl;
        }
    }

    // Пример для обычных типов
    {
        int i = create<int>();
        double d = create<double>();
        std::string s = create<std::string>();

        std::cout << "int: "    << i << std::endl;
        std::cout << "double: " << d << std::endl;
        std::cout << "string: " << s << std::endl;
    }

    return 0;
}
