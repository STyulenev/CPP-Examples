#pragma once

#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>
#include <string>
#include <functional>

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
    std::cout << "Filter:\n";
    for (const auto& name : uniqueNames) {
        std::cout << name << "\n";
    }
}

} // namespace Example_3



namespace Example_4 { // ----------------------------------- Сортировка + пропуск + взять

struct MyClass {
    int id;
    std::string name;
};

/*inline bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}*/

/*inline bool operator>(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id > rhs.id;
}*/

// less
inline bool operator<(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id < rhs.id;
}

/*
inline bool operator>=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id >= rhs.id;
}

inline bool operator<=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id <= rhs.id;
}*/

struct sort_less_fn : std::ranges::range_adaptor_closure<sort_less_fn>
{
    template<std::ranges::random_access_range R>
    auto operator()(R&& r) const
    {
        std::ranges::sort(r, std::less{});
        return std::forward<R>(r);
    }

    template<std::ranges::random_access_range R>
    friend auto operator|(R&& r, const sort_less_fn& adaptor)
    {
        return adaptor(std::forward<R>(r));
    }
};

inline constexpr sort_less_fn sort_less;

void test()
{
    std::vector<MyClass> v{
        { 5, "name5" },
        { 6, "name6" },
        { 7, "name7" },
        { 8, "name8" },
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" },
        { 9, "name9" },
        { 10, "name10" }
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    std::ranges::for_each(v | sort_less | std::views::drop(2) | std::views::take(2), show);
}

} // namespace Example_4

} // namespace Others
