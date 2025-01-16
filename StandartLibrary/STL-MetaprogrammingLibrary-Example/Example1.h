#pragma once

#include <array>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                                 Type traits: Type properties
 * =======================================================================================================================================================================
 *
 * Функции:
 * - is_void
 * - is_null_pointer
 * - is_integral
 * - is_floating_point
 * - is_array
 * - is_enum
 * - is_union
 * - is_class
 * - is_function
 * - is_pointer
 * - is_lvalue_reference
 * - is_rvalue_reference
 * - is_member_object_pointer
 * - is_member_function_pointer
 *
 */

namespace Example1 {

namespace TP1 { // ------------------------------------ Проверка на указатель общего назначения (is_void)

template <typename T, std::enable_if_t<std::is_void_v<T>, bool> = true>
void foo(T* arg)
{}

void test()
{
    void* ptr; // Указатель общего назначения
    int* i = new int(5);
    float* f = new float(5.5);

    ptr = i; // или = f;

    foo(ptr);   // Ок void
    //foo(10U); // Ошибка unsigned int
    //foo('A'); // Ошибка char
    //foo(i);   // Ошибка int*
    //foo(f);   // Ошибка float*

    delete i;
    delete f;
}

} // TP1



namespace TP2 { // ------------------------------------ Проверка на нулевой указатель (is_null_pointer)

template <typename T, std::enable_if_t<std::is_null_pointer<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    std::nullptr_t n_ptr1;
    int* n_ptr2 = nullptr;
    int* i = new int(5);
    float* f = new float(5.5);

    foo(n_ptr1);   // Ок std::nullptr_t
    //foo(n_ptr2); // Ошибка nullptr
    //foo(i);      // Ошибка int*
    //foo(f);      // Ошибка float*

    delete i;
    delete f;
}

} // TP2



namespace TP3 { // ------------------------------------ Проверка на целочисленный аргумент (is_integral)

template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
void foo(T arg)
{}

void test()
{
    foo(10U);     // Ок unsigned int
    foo(2048L);   // Ок long
    foo(2048UL);  // Ок unsigned long
    foo(-4096LL); // Ок long long
    foo(4096ULL); // Ок unsigned long long
    foo('A');     // Ок char

    //foo(10.56f); // Ошибка float
    //foo(10.56);  // Ошибка double
    //foo(10.56l); // Ошибка long double
}

} // TP3



namespace TP4 { // ------------------------------------ Проверка на аргумент с плавающей точкой (is_floating_point)

template <typename T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
void foo(T arg)
{}

void test()
{

    //foo(10U);     // Ошибка unsigned int
    //foo(2048L);   // Ошибка long
    //foo(2048UL);  // Ошибка unsigned long
    //foo(-4096LL); // Ошибка long long
    //foo(4096ULL); // Ошибка unsigned long long
    //foo('A');     // Ошибка char

    foo(10.56f); // Ок float
    foo(10.56);  // Ок double
    foo(10.56l); // Ок long double
}

} // TP4



namespace TP5 { // ------------------------------------ Проверка на массив си / std::array (is_array)

// Проверка на массив си

template<class T>
struct is_array : std::false_type {};

template<class T>
struct is_array<T[]> : std::true_type {};

template<class T, std::size_t N>
struct is_array<T[N]> : std::true_type {};

template<typename T, std::enable_if_t<std::is_array_v<std::remove_cvref_t<T>>, bool> = true> // Используя is_array
// template <typename T, typename = std::enable_if_t<std::is_array_v<T>>>                    // Используя стандартный std::is_array_v
void foo1(T& a) // Если убрать &, то необходимо не забыть проверить тип (м.б. ошибка при автоматизации и SFINAE не пропустит)
{
    std::cout << std::size(a) << std::endl;
}

// Проверка на массив std::array

template<class T>
struct is_std_array : std::false_type {};

template<class T, size_t N>
struct is_std_array<std::array<T, N>> : std::true_type {};

template<class T>
constexpr bool is_std_array_v = is_std_array<std::remove_cvref_t<T>>::value;

template<typename T, std::enable_if_t<is_std_array_v<T>, bool> = false>
void foo2(T a)
{
    std::cout << a.size() << std::endl;
}

void test()
{
    int array[] = {1, 2, 3, 4};
    std::array<int, 2> array2;

    foo1(array);    // Ок
    //foo1(array2); // Ошибка

    //foo2(array);  // Ошибка
    foo2(array2);   // Ок
}

} // TP5



namespace TP6 { // ------------------------------------ Проверка на enum (is_enum)

class Base {};

enum Enum {
    FIRST = 1,
    SECOND = 2
};

struct BaseE {
    enum Enum {
        FIRST = 1,
        SECOND = 2
    };
};

enum class EBase : int {
    FIRST = 1,
    SECOND = 2
};

template<class T, std::enable_if_t<std::is_enum_v<T>, bool> = true>
void foo(const T&& t){
    // ...
}

void test()
{
    // foo(Base());          // Ошибка
    foo(Enum::FIRST);        // Ок
    //foo(BaseE());          // Ошибка
    foo(BaseE::Enum::FIRST); // Ок
    foo(EBase::SECOND);      // Ок
}

} // TP6



namespace TP7 { // ------------------------------------ Проверка на union (is_union)

struct SomeStruct {};
class SomeClass {};

union SomeUnion
{
    int a;
    float b;
};

// Несколько видов записей для условия is_union

//template <typename T, std::enable_if_t<std::is_union_v<T>, bool> = true>
//template <typename T, std::enable_if_t<std::is_union<T>::value, bool> = true>
template <typename T, typename = std::enable_if_t<std::is_union<T>::value>>
void foo(T arg)
{}

void test()
{
    SomeClass sc;
    SomeStruct ss;
    SomeUnion su;

    //foo(sc); // Ошибка
    //foo(ss); // Ошибка
    foo(su);   // Ок
}

} // TP7



namespace TP8 { // ------------------------------------ Проверка на class (is_class)

struct SomeStruct {};

// Другие похожие проверки - is_object (объект), is_scalar (скаляр), is_compound (состовной тип - массив, функция, класс и т.д.),
// is_member_pointer (указателя на нестатический член класса).
template <typename T, typename = std::enable_if_t<std::is_class<T>::value>>
void foo(T arg)
{}

void test()
{
    SomeStruct ss;

    foo(ss);                 // Ок
    //foo(12);               // Ошибка
    //foo(14.4);             // Ошибка
    //foo('a');              // Ошибка
    foo(std::string("sdf")); // Ок
}

} // TP8



namespace TP9 { // ------------------------------------ Проверка на функцию (is_function)

template<class>
struct is_function : std::false_type { /*static const bool value = false;*/ };

// specialization for regular functions
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : std::true_type { /*static const bool value = true;*/ };

// Необходимо удалить указатель при проверке
template <typename T, std::enable_if_t<is_function<std::remove_pointer_t<T>>::value, bool> = true >  // Используя is_function
//template <typename T, std::enable_if_t<std::is_function_v<std::remove_pointer_t<T>>, bool> = true> // Используя стандартный std::is_function_v
void foo(T arg)
{
    arg();
}

void func() {
    std::cout << "funс" << std::endl;
}

void test()
{
    // lambda не функция, а класс с переопределенным operator()
    auto lambda = []() -> void {
        std::cout << "func" << std::endl;
    };

    foo /*<void(void)>*/ (func);     // Ок
    //foo /*<void(void)>*/ (lambda); // Ошибка
    //foo /* <int> */ (12);          // Ошибка
}

} // TP9



namespace TP10 { // ------------------------------------ Проверка на указатель в аргументе функции (is_pointer)

// std::false_type/std::true_type === static const bool value = false/true;

class Base {};

template<typename T>
struct is_pointer /*: std::false_type*/ { static const bool value = false; };

template<typename T>
struct is_pointer<T*> /*: std::true_type*/ { static const bool value = true; };

template <typename T, std::enable_if_t<is_pointer<T>::value, bool> = true >   // Используя is_pointer
//template <typename T, std::enable_if_t<std::is_pointer_v<T>, bool> = true > // Используя стандартный std::is_pointer_v
void foo(T arg)
{}

void test()
{
    Base* b = new Base();
    Base b1;

    foo(b);    // Ок
    //foo(b1); // Ошибка
    //foo(12); // Ошибка

    delete b;
}

} // TP10



namespace TP11 { // ------------------------------------ Проверка на lvalue (is_lvalue_reference)

template<class T> struct is_lvalue_reference      : std::false_type {};
template<class T> struct is_lvalue_reference<T&>  : std::true_type {};

template <typename T, std::enable_if_t<is_lvalue_reference<T>::value, bool> = true>   // Используя is_lvalue_reference
//template <typename T, std::enable_if_t<std::is_lvalue_reference_v<T>, bool> = true> // Используя стандартный std::is_lvalue_reference_v
void foo(T arg)
{
    std::cout << "lvalue" << std::endl;
}

void test()
{
    int a = 19;
    int &a_ref = a;

    // Необходимо указывать тип шаблону, чтобы не произошло сворачивание ссылки:
    // T & & -> T &: Если мы попытаемся сформировать ссылку на ссылку, где обе являются ссылками lvalue (&), она сворачивается в единственную ссылку lvalue.
    // T & && -> T &: Если у нас есть ссылка lvalue на ссылку rvalue, она сворачивается до ссылки lvalue.
    // T && & -> T &: Если у нас есть ссылка rvalue на ссылку lvalue, она сворачивается до ссылки lvalue.
    // T && && -> T & &&: Если у нас есть ссылка rvalue на ссылку rvalue, она остается ссылкой rvalue.

    foo<int&>(a); // Ок
    //foo(18);    // Ошибка
}

} // TP11



namespace TP12 { // ------------------------------------ Проверка на rvalue (is_rvalue_reference)

template<class T> struct is_rvalue_reference      : std::false_type {};
template<class T> struct is_rvalue_reference<T&&> : std::true_type {};

template <typename T, std::enable_if_t<is_rvalue_reference<T>::value, bool> = true>   // Используя is_rvalue_reference
//template <typename T, std::enable_if_t<std::is_rvalue_reference_v<T>, bool> = true> // Используя стандартный std::is_rvalue_reference_v
void foo(T arg)
{
    std::cout << "rvalue" << std::endl;
}

void test()
{
    int a = 19;
    int &a_ref = a;

    // Необходимо указывать тип шаблону, чтобы не произошло сворачивание ссылки:
    // T & & -> T &: Если мы попытаемся сформировать ссылку на ссылку, где обе являются ссылками lvalue (&), она сворачивается в единственную ссылку lvalue.
    // T & && -> T &: Если у нас есть ссылка lvalue на ссылку rvalue, она сворачивается до ссылки lvalue.
    // T && & -> T &: Если у нас есть ссылка rvalue на ссылку lvalue, она сворачивается до ссылки lvalue.
    // T && && -> T & &&: Если у нас есть ссылка rvalue на ссылку rvalue, она остается ссылкой rvalue.

    //foo<int&>(a); // Ошибка
    foo<int&&>(18); // Ок
}

} // TP12



namespace TP13 { // ------------------------------------ Проверка на нестатическое поле класса (is_member_object_pointer)

class Base {
public:
    int field;

    void method1() {}
    static void method2() {}
};

template <typename T, std::enable_if_t<std::is_member_object_pointer<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    Base b;
    int Base::* pt = &Base::field;

    foo(pt);               // Ок
    //foo(&Base::method1); // Ошибка
    //foo(&Base::method2); // Ошибка
    //foo(12);             // Ошибка
}

} // TP13



namespace TP14 { // ------------------------------------ Проверка на нестатический метод класса (is_member_function_pointer)

class Base {
public:
    void method1() {}
    static void method2() {}
};

template <typename T, std::enable_if_t<std::is_member_function_pointer<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    Base b;

    foo(&Base::method1);   // Ок
    //foo(&Base::method2); // Ошибка
    //foo(12);             // Ошибка
}

} // TP14

} // namespace Example1
