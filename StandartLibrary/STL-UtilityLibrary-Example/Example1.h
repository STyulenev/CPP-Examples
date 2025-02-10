#pragma once

#include <any>
#include <expected>
#include <functional>
#include <iostream>
#include <optional>
#include <utility>
#include <variant>
#include <tuple>

/*
 * =======================================================================================================================================================================
 *                                                                   General-purpose utilities
 * =======================================================================================================================================================================
 *
 * Swap:
 * - swap
 * - exchange
 * - ranges::swap (C++20)
 *
 * Type operations:
 * - forward
 * - forward_like (C++23)
 * - move
 * - move_if_noexcept
 * - as_const
 * - declval
 * - to_underlying
 *
 * Integer comparison functions:
 * - cmp_equal (C++20)
 * - cmp_not_equal (C++20)
 * - cmp_less (C++20)
 * - cmp_greater (C++20)
 * - cmp_less_equal (C++20)
 * - cmp_greater_equal (C++20)
 * - in_range (C++20)
 *
 * Relational operators:
 * - operator!= (deprecated in C++20)
 * - operator> (deprecated in C++20)
 * - operator<= (deprecated in C++20)
 * - operator>= (deprecated in C++20)
 *
 * Construction tags:
 * - piecewise_construct
 * - piecewise_construct_t
 * - in_place
 * - in_place_type
 * - in_place_index
 * - in_place_t
 * - in_place_type_t
 * - in_place_index_t
 * - nontype (C++26)
 *
 * Pairs and tuples:
 * - pair
 * - tuple
 * - apply
 * - make_from_tuple
 * - tuple_size
 * - tuple_element
 *
 * Sum types and type erased wrappers:
 * - optional
 * - expected (C++23)
 * - variant
 * - any
 *
 */

namespace Example1 {

namespace GPU1_1 { // ----------------------------------- Swap: exchange

struct SomeClass {
    SomeClass(int a, int b) : a(a), b(b) {}

    int a;
    int b;

    // Для более сложных и больших классов следует использовать переопределенную функцию swap
    // В данном случае код сработает без неё
    /*friend void swap(SomeClass& l, SomeClass& r) {
        std::swap(l.a, r.a);
        std::swap(l.b, r.b);
        // ...
    }*/

    friend std::ostream& operator << (std::ostream &os, const SomeClass &someClass) {
        return os << someClass.a << " " << someClass.b;
    }
};

void test()
{
    // std::cout << "\nfile: " << __FILE_NAME__ << " line: " << __LINE__ << ", " << __FUNCTION__ << ":" << std::endl;

    { // Стандартная перегрузка swap для pair
        auto p1 = std::make_pair<std::string, std::string>("1", "46456"); // типы должны совпадать
        auto p2 = std::pair<std::string, std::string>("df", "df");

        std::cout << "p1 = {" << std::get<0>(p1) << ", " << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2) << ", " << std::get<1>(p2) << "}\n";

        p1.swap(p2);

        std::cout << "p1 = {" << std::get<0>(p1) << ", " << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2) << ", " << std::get<1>(p2) << "}\n";

        std::swap(p1, p2);

        std::cout << "p1 = {" << std::get<0>(p1) << ", " << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2) << ", " << std::get<1>(p2) << "}\n";
    }

    { // Для пользовательского класса
        auto sc1 = SomeClass(1, 2);
        auto sc2 = SomeClass(2, 1);

        std::cout << "sc1 = " << sc1 << ", " << "sc2 = " << sc2 << "}\n";

        std::swap(sc1, sc2);

        std::cout << "sc1 = " << sc1 << ", " << "sc2 = " << sc2 << "}\n";

        std::swap(sc2, sc1);

        std::cout << "sc1 = " << sc1 << ", " << "sc2 = " << sc2 << "}\n";
    }
}

} // namespace GPU1_1



namespace GPU1_2 { // ----------------------------------- Swap: swap

struct SomeClass {
    SomeClass(int a, int b) : a(a), b(b) {}

    int a;
    int b;

    SomeClass& operator=(SomeClass& other) noexcept
    {
        a = std::exchange(other.a, 0);
        b = std::exchange(other.b, 0);

        return *this;
    }

    friend std::ostream& operator << (std::ostream &os, const SomeClass &someClass) {
        return os << someClass.a << " " << someClass.b;
    }
};

void test()
{
    // std::cout << "\nfile: " << __FILE_NAME__ << " line: " << __LINE__ << ", " << __FUNCTION__ << ":" << std::endl;

    { // Стандартная перегрузка swap для pair
        auto p1 = std::make_pair<std::string, std::string>("1", "46456");
        auto p2 = std::make_pair<std::string, std::string>("1", "46456");

        std::cout << "p1 = {" << std::get<0>(p1) << ", " << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2) << ", " << std::get<1>(p2) << "}\n";

        p2 = std::exchange(p1, {"_", "_____"});

        std::cout << "p1 = {" << std::get<0>(p1) << ", " << std::get<1>(p1) << "}, "
                  << "p2 = {" << std::get<0>(p2) << ", " << std::get<1>(p2) << "}\n";
    }

    { // Для пользовательского класса
        auto sc1 = SomeClass(1, 2);
        auto sc2 = SomeClass(2, 1);

        std::cout << "sc1 = " << sc1 << ", " << "sc2 = " << sc2 << "}\n";

        sc1 = sc2;

        std::cout << "sc1 = " << sc1 << ", " << "sc2 = " << sc2 << "}\n";
    }
}

} // namespace GPU1_2

namespace GPU6_1 { // ----------------------------------- Pairs and tuples: pair

void print(int a, double b)
{
    std::cout << "pair { " << a << ", " << b << " }"<< std::endl;
}

struct PrintS {
    void operator()(const std::pair<int, double>& p) const
    {
        std::cout << "pair { " << p.first << ", " << p.second << " }"<< std::endl;
    }
};

void test()
{
    { // Списобы инициализации
        std::pair<int, double> p1 = std::make_pair(1, 2.3);
        std::pair<int, double> p2 (1, 2.3);
        std::pair<int, double> p3 = { 1, 2.3 };
        auto p4 = std::make_pair(1, 2.3);
    }

    { // std::get
        auto p = std::make_pair("...", 2.3);

        std::cout << "pair { " << std::get<0>(p) << ", " << std::get<1>(p) << " }"<< std::endl;
    }

    { // std::apply
        std::pair<int, double> p = std::make_pair(1, 2.3);

        std::apply(print, p);
    }

    { // std::invoke
        auto printL = [](const std::pair<int, double>& p) -> void {
            std::cout << "pair { " << p.first << ", " << p.second << " }"<< std::endl;
        };

        std::pair<int, double> p = std::make_pair(1, 2.3);

        std::invoke(printL, p);
        std::invoke(PrintS(), p);
    }
}

} // namespace GPU6_1



namespace GPU6_2 { // ----------------------------------- Pairs and tuples: tuple

void print(int a, double b, const std::string& c)
{
    std::cout << "tuple { " << a << ", " << b << ", " << c << " }"<< std::endl;
}

struct PrintS {
    void operator()(const std::tuple<int, double, std::string>& t) const
    {
        std::cout << "tuple { " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << " }"<< std::endl;
    }
};

void test()
{
    { // Списобы инициализации
        std::tuple<int, double, std::string> t1 = std::make_tuple(1, 2.3, "...");
        std::tuple<int, double, std::string> t2 (1, 2.3, "...");
        std::tuple<int, double, std::string> t3 = { 1, 2.3, "..." };
        auto t4 = std::make_tuple(1, 2.3, "...");
    }

    { // Получение элементов через std::get
        auto t = std::make_tuple(1, 2.3, std::string("..."));

        std::cout << "tuple { " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << " }"<< std::endl;
        std::cout << "tuple { " << std::get<int>(t) << ", " << std::get<double>(t) << ", " << std::get<std::string>(t) << " }"<< std::endl;
    }

    { // std::apply
        auto t = std::make_tuple(1, 2.3, std::string("..."));

        std::apply(print, t);
    }

    { // std::invoke
        auto printL = [](const std::tuple<int, double, std::string>& t) -> void {
            std::cout << "tuple { " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << " }"<< std::endl;
        };

        auto t = std::make_tuple(1, 2.3, std::string("..."));

        std::invoke(printL, t);
        std::invoke(PrintS(), t);
    }

    { // Получение элементов через auto []
        auto lambda = []() { return std::make_tuple(1, 2.3, std::string("...")); };
        auto [a, b, c] = lambda();
        print(a, b, c);
    }

    { // Получение элементов через std::tie
        auto lambda = []() { return std::make_tuple(1, 2.3, std::string("...")); };

        int a;
        double b;
        std::string c;

        std::tie(a, b, c) = lambda();

        print(a, b, c);
    }

    { // std::tuple_cat
        int n1 = 0;
        int n2 = 9;
        auto tc = std::tuple_cat(std::tie(n1), std::make_tuple(1, 2.3, std::string("...")), std::tie(n2));

        std::cout << "tuple_cat { " << std::get<0>(tc) << ", " << std::get<1>(tc) << ", " << std::get<2>(tc) << ", " << std::get<3>(tc) << ", " << std::get<4>(tc) <<" }"<< std::endl;
    }
}

} // namespace GPU6_2



namespace GPU6_3 { // ----------------------------------- Pairs and tuples: apply

void print1(int a, double b)
{
    std::cout << "print { " << a << ", " << b << " }"<< std::endl;
}

void print2(int a, double b, const std::string& c)
{
    std::cout << "print { " << a << ", " << b << ", " << c << " }"<< std::endl;
}

void print3(int a, int b)
{
    std::cout << "print { " << a << ", " << b << " }"<< std::endl;
}

void test()
{
    { // std::pair
        auto p = std::make_pair(1, 2.3);
        std::apply(print1, p);
    }

    { // std::tuple
        auto t = std::make_tuple(1, 2.3, std::string("..."));
        std::apply(print2, t);
    }

    { // std::array
        std::array<int, 2> a = {1, 2};
        std::apply(print3, a);
    }

}

} // namespace GPU6_3



namespace GPU7_1 { // ----------------------------------- Sum types and type erased wrappers: optional

void test()
{
    // std::cout << "\nfile: " << __FILE_NAME__ << " line: " << __LINE__ << ", " << __FUNCTION__ << ":" << std::endl;

    {
        auto lambda = [](bool status) -> std::optional<std::string> {
            if (status)
                return "Not empty std::optional";
            else
                return {};
        };

        std::cout << lambda(true).value() << std::endl;
        std::cout << lambda(false).value_or("Empty std::optional") << std::endl;
    }

    {
        std::optional<std::string> opt = std::make_optional("Not empty std::optional");

        if (opt.has_value()) {
            std::cout << "opt.has_value() == true, value = " << opt.value() << std::endl;
        }

        opt.reset(); // уничтожаем значение

        if (!opt.has_value()) {
            std::cout << "opt.has_value() == false" << std::endl;
        }
    }

    {
        std::optional<std::string> opt;

        try {
            std::cout << opt.value() << std::endl;
        } catch (const std::bad_optional_access& error) {
            std::cout << error.what() << std::endl;
        }
    }
}

} // namespace GPU7_1



namespace GPU7_2 { // ----------------------------------- Sum types and type erased wrappers: expected

std::expected<int, double> check(bool status)
{
    if (status)
        return 1;
    else
        return std::unexpected(1.1);
}

void test()
{
    auto result1 = check(true);
    std::cout << "value = " << *result1 << std::endl;

    auto result2 = check(false);
    std::cout << "value = " << result2.error() << std::endl;
}

} // namespace GPU7_2



namespace GPU7_3 { // ----------------------------------- Sum types and type erased wrappers: variant

struct PrintVariant {
    void operator()(const int n) { std::cout << "variant value = " << n << std::endl; }
    void operator()(const std::string& str) { std::cout << "variant value = " << str << std::endl; }
    void operator()(const bool status) { std::cout << std::boolalpha << "variant value = " << status << std::endl; }
};

void test()
{
    // std::cout << "\nfile: " << __FILE_NAME__ << " line: " << __LINE__ << ", " << __FUNCTION__ << ":" << std::endl;

    { // std::variant и std::get
        std::variant<int, std::string, bool> variant;

        variant = true;

        try {
            [[maybe_unused]] bool status = std::get<bool>(variant);            // Ок
            [[maybe_unused]] std::string str = std::get<std::string>(variant); // Ошибка
        } catch(const std::bad_variant_access& ex) {
            std::cout << "std::variant error: " << ex.what() << std::endl;
        }
    }

    { // std::get_if
        std::variant<int, std::string, bool> variant;

        variant = true;

        if (const int* val = std::get_if<int>(&variant)) {
            std::cout << "variant value = " << *val << std::endl;
        } else {
            std::cout << "variant invalid" << std::endl;
        }
    }

    { // std::visit
        std::variant<int, std::string, bool> variant;

        variant = true;
        std::visit(PrintVariant{}, variant);

        variant = std::string("hello");
        std::visit(PrintVariant{}, variant);

        variant = 34;
        std::visit(PrintVariant{}, variant);
    }

    { // std::holds_alternative
        std::variant<int, std::string, bool> variant;

        variant = 34; //true; // std::string("hello");

        if (std::holds_alternative<int>(variant)) {
            std::cout << "holds_alternative = true" << std::endl;
        } else {
            std::cout << "holds_alternative = false" << std::endl;
        }
    }
}

} // namespace GPU7_3

namespace GPU7_4 { // ----------------------------------- Sum types and type erased wrappers: any

void test()
{
    // std::cout << "\nfile: " << __FILE_NAME__ << " line: " << __LINE__ << ", " << __FUNCTION__ << ":" << std::endl;

    {
        std::any any;

        if (!any.has_value()) {
            std::cout << "any.has_value() == false" << std::endl;
        }

        any = 5;

        if (any.has_value()) {
            std::cout << "any.has_value() == true" << std::endl;
        }

        try {
            //bool value = std::any_cast<bool>(any); // throw
            int value = std::any_cast<int>(any);

            std::cout << "value = " << value << std::endl;
        } catch (const std::bad_any_cast& error) {
            std::cout << error.what() << std::endl;
        }
    }

    {
        std::any any;

        any = 5;

        std::cout << "any.type() = " << any.type().name() << std::endl;

        if (any.type() == typeid(int)) {
            int value = std::any_cast<int>(any);

            std::cout << "value = " << value << std::endl;
        }

        any.reset();

        std::cout << "any.type() = " << any.type().name() << std::endl;
    }
}

} // namespace GPU7_4

} // namespace Example1
