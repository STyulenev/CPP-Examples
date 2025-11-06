#include <iostream>
#include <map>

/*
 * Structured binding declaration (деструктурирующее связывание) - это механизм декомпозиции объекта на отдельные переменные.
 * Вместо работы с целым объектом (кортежем, структурой, массивом) можно "разобрать" его на отдельные компоненты/переменные.
 */

struct SomeStruct
{
    int a;
    int b;
    int c;
};

int main()
{
    { // Декомпозиция объекта при создании
        auto [a, b, c] = SomeStruct();

        std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    }

    { // Декомпозиция объекта при получении из функции
        auto [a, b, c] = []() -> SomeStruct {
            return SomeStruct();
        }();

        std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    }

    { // Декомпозиция пары/кортежа
        auto [a, b] = std::make_pair<int, int>(1, 2);
        //auto [a, b, c] = std::make_tuple<int, int, int>(1, 2, 3);

        std::cout << "a = " << a << ", b = " << b << "\n";
    }

    { // Декомпозиция массива
        int arr[3] = {1, 2, 3};
        auto& [a, b, c] = arr; // a=1, b=2, c=3

        arr[0] = 5; // a=5
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    }

    { // Декомпозиция карты
        std::map<std::string, int> cities = {
            { "Moscow", 12 },
            { "London", 9 }
        };

        // Новый способ
        for (const auto& [city, population] : cities) {
            std::cout << city << ": " << population << std::endl;
        }
    }

    return 0;
}
