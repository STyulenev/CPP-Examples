#pragma once

#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>
#include <string>


namespace Others {

namespace Example_1 { // ----------------------------------- Swap: exchange

struct SomeClass
{
    int id;
    std::string name;

    friend std::ostream& operator<<(std::ostream& os, const SomeClass& obj) {
        os << obj.id << " " << obj.name << "\n";
        return os;
    }

    /*friend bool operator<(const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.id < rhs.id;
    }

    friend bool operator>(const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.id > rhs.id;
    }

    friend bool operator==(const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.id == rhs.id;
    }

    friend bool operator<=(const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.id <= rhs.id;
    }

    friend bool operator>=(const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.id <= rhs.id;
    }*/
};

void test()
{
    std::vector<SomeClass> v = {
        SomeClass{ 1, "first"  },
        SomeClass{ 2, "first"  },
        SomeClass{ 3, "first"  },
        SomeClass{ 1, "second" },
        SomeClass{ 2, "second" },
        SomeClass{ 3, "second" },
        SomeClass{ 1, "third"  },
        SomeClass{ 2, "third"  },
        SomeClass{ 3, "third"  },
        SomeClass{ 1, "fourth" },
        SomeClass{ 2, "fourth" },
        SomeClass{ 3, "fourth" },

        SomeClass{ 1, "first"  },
        SomeClass{ 2, "first"  },
        SomeClass{ 3, "first"  },
        SomeClass{ 1, "second" },
        SomeClass{ 2, "second" },
        SomeClass{ 3, "second" },
        SomeClass{ 1, "third"  },
        SomeClass{ 2, "third"  },
        SomeClass{ 3, "third"  },
        SomeClass{ 1, "fourth" },
        SomeClass{ 2, "fourth" },
        SomeClass{ 3, "fourth" }
    };

    std::ranges::sort(v, [](const SomeClass& lhs, const SomeClass& rhs) {
        return lhs.name < rhs.name;
    });

    for (const SomeClass& f : v) {
        std::cout << f;
    }

    auto filter = v |
                  std::views::filter([](const SomeClass& sc) { return sc.id == 1; });

    std::cout << std::endl << std::endl;

    for (const SomeClass& f : filter) {
        std::cout << f;
    }


    auto filter2 = std::ranges::unique(filter, [](const SomeClass& lhs, const SomeClass& rhs) { return lhs.name == rhs.name; });

    std::cout << std::endl << std::endl;

    for (auto& f : filter2) {
        std::cout << f.id << " " << f.name << "\n";
    }

}

} // namespace Example_1



namespace Example_2 {

// Определяем структуру
struct SomeClass {
    int id;
    std::string name;

    // Оператор вывода для удобного вывода объектов
    friend std::ostream& operator<<(std::ostream& os, const SomeClass& obj) {
        return os << "{" << obj.id << ", " << obj.name << "}";
    }
};

// Функция для фильтрации по условию 10 < id < 20
bool filterById(const SomeClass& obj) {
    return obj.id > 10 && obj.id < 20;
}

// Функция сравнения для сортировки по name
bool compareByName(const SomeClass& a, const SomeClass& b) {
    return a.name < b.name;
}

void test()
{
    // Создаем вектор с тестовыми данными
    std::vector<SomeClass> data = {
        {5, "John"},
        {12, "Alice"},
        {15, "Bob"},
        {25, "Charlie"},
        {18, "Alice"},
        {14, "Eve"},
        {8, "Frank"},
        {17, "Grace"}
    };

    // Фильтруем данные по условию 10 < id < 20
    std::vector<SomeClass> filteredData;
    std::copy_if(data.begin(), data.end(), std::back_inserter(filteredData), filterById);

    // Сортируем отфильтрованные данные по name
    std::sort(filteredData.begin(), filteredData.end(), compareByName);

    // Создаем множество для хранения уникальных имен
    std::set<std::string> uniqueNames;

    // Заполняем множество уникальными именами
    for (const auto& obj : filteredData) {
        uniqueNames.insert(obj.name);
    }

    // Выводим результат
    std::cout << "#2:\n";
    for (const auto& name : uniqueNames) {
        std::cout << name << "\n";
    }
}

} // namespace Example_2



namespace Example_3 {

// Определяем структуру
struct SomeClass {
    int id;
    std::string name;

    // Оператор вывода для удобного вывода объектов
    friend std::ostream& operator<<(std::ostream& os, const SomeClass& obj) {
        return os << "{" << obj.id << ", " << obj.name << "}";
    }
};

// Функция для фильтрации по условию 10 < id < 20
bool filterById(const SomeClass& obj) {
    return obj.id > 10 && obj.id < 20;
}

// Функция сравнения для сортировки по name
bool compareByName(const SomeClass& a, const SomeClass& b) {
    return a.name < b.name;
}

void test()
{
    // Создаем вектор с тестовыми данными
    std::vector<SomeClass> data = {
        {5, "John"},
        {12, "Alice"},
        {15, "Bob"},
        {25, "Charlie"},
        {18, "Alice"},
        {14, "Eve"},
        {8, "Frank"},
        {17, "Grace"}
    };

    // Фильтруем данные по условию 10 < id < 20
    auto filtered = data | std::views::filter(filterById);

    // Копируем отфильтрованные данные во временный вектор
    std::vector<SomeClass> temp(filtered.begin(), filtered.end());

    // Сортируем отфильтрованные данные по name
    std::ranges::sort(temp, compareByName);

    // Создаем множество для хранения уникальных имен
    std::set<std::string> uniqueNames;

    // Заполняем множество уникальными именами
    for (const auto& obj : temp) {
        uniqueNames.insert(obj.name);
    }

    // Выводим результат
    std::cout << "Отфильтрованные и отсортированные уникальные имена:\n";
    for (const auto& name : uniqueNames) {
        std::cout << name << "\n";
    }
}

} // namespace Example_3

} // namespace Others
