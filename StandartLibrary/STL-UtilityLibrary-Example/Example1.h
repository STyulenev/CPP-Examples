#pragma once

#include <any>
#include <iostream>
#include <optional>
#include <utility>
#include <variant>

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

namespace GPU1_1 { // ----------------------------------- Swap: swap

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
