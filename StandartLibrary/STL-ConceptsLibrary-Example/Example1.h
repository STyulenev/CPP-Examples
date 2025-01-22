#pragma once

#include <concepts>
#include <iostream>

#include <memory>

/*
 * =======================================================================================================================================================================
 *                                                                 Core language concepts
 * =======================================================================================================================================================================
 *
 * Функции:
 * - same_as
 * - derived_from
 * - convertible_to
 * - common_reference_with
 * - common_with
 * - integral
 * - signed_integral
 * - unsigned_integral
 * - floating_point
 * - assignable_from
 * - swappable
 * - swappable_with
 * - destructible
 * - constructible_from
 * - default_initializable
 * - move_constructible
 * - copy_constructible
 *
 */

namespace Example1 {

namespace CL1 { // ------------------------------------ Проверка на тип (same_as)

template <class T>
concept IsInt = std::same_as<T, int>; // || std::convertible_to<T, int>

template <class T> requires IsInt<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    //foo(i);                 // Ошибка
    //foo(12L);               // Ошибка
    //foo('c');               // Ошибка
    //foo(2.1);               // Ошибка
    //foo(std::string("12")); // Ошибка
}

} // namespace CL1



namespace CL2 { // ------------------------------------ Проверка на наследуемость (derived_from)

class Base {};

class D1 : public Base {};

class D2 : private Base {};

template <class T>
concept IsDerivedFromBase = std::derived_from<T, Base>;

template <class T> requires IsDerivedFromBase<T>
void foo(T arg)
{}

void test()
{
    Base b;
    D1 d1;
    D2 d2;

    foo(b);     // Ок
    foo(d1);    // Ок
    //foo(d2);  // Ошибка
    //foo(12L); // Ошибка
}

} // namespace CL2



namespace CL3 { // ------------------------------------ Проверка на конвертируемость (convertible_to)

template <class T>
concept IsToInt = std::same_as<T, int> || std::convertible_to<T, int>;

template <class T> requires IsToInt<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    foo(i);                   // Ок
    foo(12L);                 // Ок
    foo('c');                 // Ок
    foo(2.1);                 // Ок
    //foo(std::string("12")); // Ошибка
}

} // namespace CL3



namespace CL4 { // ------------------------------------ Проверка на ссылочный тип (common_reference_with)

class Base {};

class D1 : public Base {};

class D2 : private Base {};

template <class T>
concept IsRefBase = std::common_reference_with<T, Base>;

template <class T> requires IsRefBase<T>
void foo(T arg)
{}

void test()
{
    Base b;
    D1 d1;
    D2 d2;

    foo(std::move(b));    // Ок
    foo(std::move(d1));   // Ок
    //foo(std::move(d2)); // Ошибка
    //foo(12L);           // Ошибка
}

} // namespace CL4



namespace CL5 { // ------------------------------------ Проверка на общий тип к которому можно преобразовать (common_with)

class Base {};

class D1 : public Base {};

class D2 : public Base {};

class D3 {};

template <class T>
concept HasCommonBase = std::common_with<T, Base>;

template <class T> requires HasCommonBase<T>
void foo(T arg)
{}

void test()
{
    Base b;
    D1 d1;
    D2 d2;
    D3 d3;

    foo(b);    // Ок
    foo(d1);   // Ок
    foo(d2);   // Ок
    //foo(d3); // Ошибка
    //foo(12); // Ошибка
}

} // namespace CL5



namespace CL6 { // ------------------------------------ Проверка на целочисленный тип (integral)

template <class T>
concept IsIntegral = std::integral<T>;

template <class T> requires IsIntegral<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    foo(i);                   // Ок
    foo(12L);                 // Ок
    foo('c');                 // Ок
    //foo(2.1);               // Ошибка
    //foo(std::string("12")); // Ошибка
}

} // namespace CL6



namespace CL7 { // ------------------------------------ Проверка на знаковый целочисленный тип (signed_integral)

template <class T>
concept IsSignedIntegral = std::signed_integral<T>;

template <class T> requires IsSignedIntegral<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    //foo(i);                 // Ошибка
    foo(12L);                 // Ок
    foo('c');                 // Ок
    //foo(2.1);               // Ошибка
    //foo(std::string("12")); // Ошибка
}

} // namespace CL7



namespace CL8 { // ------------------------------------ Проверка на беззнаковый целочисленный тип (unsigned_integral)

template <class T>
concept IsUnsignedIntegral = std::unsigned_integral<T>;

template <class T> requires IsUnsignedIntegral<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    //foo(12);                // Ошибка
    foo(i);                   // Ок
    //foo(12L);               // Ошибка
    //foo('c');               // Ошибка
    //foo(2.1);               // Ошибка
    //foo(std::string("12")); // Ошибка
}

} // namespace CL8



namespace CL9 { // ------------------------------------ Проверка на дробный тип (floating_point)

template <class T>
concept IsFloating = std::floating_point<T>;

template <class T> requires IsFloating<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    //foo(12);                // Ошибка
    //foo(i);                 // Ошибка
    //foo(12L);               // Ошибка
    //foo('c');               // Ошибка
    foo(2.1);                 // Ок
    foo(2.1F);                // Ок
    //foo(std::string("12")); // Ошибка
}

} // namespace CL9



namespace CL10 { // ------------------------------------ Проверка на назначаемый из тип (assignable_from)

template <class T>
concept IsFromInt = std::assignable_from<T, int>;

template <class T> requires IsFromInt<T>
void foo(T arg)
{}

void test()
{
    int i = 12;
    int& ref = i;

    foo<int&>(ref); // Оk
    //foo(i);       // Ошибка
    //foo(2.1);     // Ошибка
}

} // namespace CL10



namespace CL11 { // ------------------------------------ Проверка на swap (swappable)


struct Base1 {
    int field;

    Base1(int field) : field(field) {}

    friend void swap(Base1& lhs, Base1& rhs) noexcept {
        std::swap(lhs.field, rhs.field);
    }
};

struct Base2 {
    int field;

    Base2(int field) : field(field) {}
};

template <class T>
concept IsSwap = std::swappable<T>;

template <class T> requires IsSwap<T>
void foo(T arg1, T arg2)
{}

void test()
{
    Base1 b1_1(1);
    Base1 b2_1(2);

    Base2 b1_2(1);
    Base2 b2_2(2);

    foo(b1_1, b2_1);   // Оk
    //foo(b1_2, b2_1); // Ошибка
    foo(2, 2);         // Оk
}

} // namespace CL11



namespace CL12 { // ------------------------------------ Проверка на swap (swappable_with)


struct Base {
    int field;

    Base(int field) : field(field) {}

    friend void swap(Base& lhs, Base& rhs) noexcept {
        std::swap(lhs.field, rhs.field);
    }
};

template <class T, class U>
concept IsSwap = std::swappable_with<T, U>;

template <class T, class U> requires IsSwap<T, U>
void foo(T&& arg1, U&& arg2)
{}

/*template <class T, class U> requires std::swappable_with<T,U>
void mySwap(T&& t, U&& u) {
    auto temp = std::forward<T>(t);
    t = std::forward<U>(u);
    u = std::move(temp);
}*/

void test()
{
    Base b1(1);
    Base b2(2);

    foo(b1, b2); // Оk
    //foo(2, 2); // Ошибка
}

} // namespace CL12



namespace CL13 { // ------------------------------------ Проверка на удаляемость (destructible)

class Base1 {};

class Base2
{
public:
    Base2() {}

    static Base2& getBase2() {
        static Base2 b2;

        return b2;
    }

private:
    ~Base2() {}
};

template <class T>
concept IsDestructible = std::destructible<T>;

template <class T> requires IsDestructible<T>
void foo(T arg)
{}

void test()
{
    Base1 b1;

    foo(b1);                  // Ок
    //foo(Base2::getBase2()); // Ошибка
}

} // namespace CL13

} // namespace Example1
