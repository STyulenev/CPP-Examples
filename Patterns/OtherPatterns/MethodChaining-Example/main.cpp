#include "SomeClass.h"

#include <vector>
#include <ranges>

/*
 * Method Chaining (Цепочка методов) в C++ — это когда метод возвращает ссылку на объект-владелец или новосозданный элемент с последующим
 * вызывом над ним нового метода/функции.
 */

int main()
{
    // Пример на основе пользовательского класса
    {
        { // С цепочкой методов
            SomeClass someClass;
            someClass.setFirstField(0.1).setSecondField(12).setThirdField("some text").setFirstField(0.2);

            someClass << "." << "." << ".";

            std::cout << someClass << std::endl;
        }

        { // Без цепочки методов
            SomeClass someClass;
            someClass.setFirstField(0.1);
            someClass.setSecondField(12);
            someClass.setThirdField("some text");
            someClass.setFirstField(0.2);
            someClass.setThirdField("some text...");

            std::cout << someClass << std::endl;
        }
    }

    // Пример с использованием \ и вектора
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        for (const int i : numbers
                               | std::views::filter([](int n) -> bool { return n % 2 == 0; })
                               | std::views::transform([](int n) -> int { return n * 2; }))
        {
            std::cout << "i = " << i  << std::endl;
        }
    }

    // Пример с использованием << и вывода данных
    {
        std::cout << "first..." << "second..." << "..." << std::endl;
    }

    return 0;
}
