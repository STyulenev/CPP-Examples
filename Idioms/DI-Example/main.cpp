#include <iostream>
#include <experimental/type_traits>

/*
 * Идиома обнаружения (Detection idiom) — это идиома, которая позволяет проводить проверку типов во время компиляции в C++. Используя идиому обнаружения,
 * можно проверить, есть ли у типа методы, псевдонимы типов или члены, которые соответствуют определенному интерфейсу. Ниже представлены несколько вариантов
 * идиомы обнаружения для разных стандартов C++.
 */

// До C++ 11 (используя sizeof)
namespace V1 {

template <typename T>
T declval();

template <typename T>
struct hasGetMethod {
    typedef char yes[1];
    typedef char no[2];

    // Проверка на get метод. Вызывается если есть get()
    template <typename U>
    static yes& get(int (*)[sizeof(declval<U>().get(), 1)]);

    // Проверка на get метод. Вызывается если нет get()
    template <typename U>
    static no& get(...);

    static const bool value = sizeof(get<T>(NULL)) == sizeof(yes);
};

} // namespace V1

// C++ 11 (используя SFINAE)
namespace V2 {
    template <typename T>
    struct hasGetMethod {

        // Проверка на get метод. Вызывается если есть get()
        template <typename U>
        static constexpr decltype(std::declval<U>().get(), bool()) get(int) {
            return true;
        }

        // Проверка на get метод. Вызывается если нет get()
        template <typename U>
        static constexpr bool get(...) {
            return false;
        }

        static constexpr bool value = get<T>(int());
    };
} // namespace V2

// После C++ 11 (используя методы из type_traits)
namespace V3 {

template <typename T>
using get = decltype(std::declval<T>().get());

template <typename T>
using hasGetMethod = std::experimental::is_detected<get, T>;

} // namespace V3


// C++ 20 (используя концепты)
namespace V4 {

template<typename T>
concept get = requires(T a)
{
    // Проверка на get метод
    { a.get() };
};

template <typename T>
bool hasGetMethod() requires get<T>
{
    return true;
}

template <typename T>
bool hasGetMethod()
{
    return false;
}

} // namespace V4

// Тестовые структуры
struct foo1
{
    int get() { return 0; }
};

struct foo2
{
    void set() { }
};

int main()
{
    std::cout << "V1. foo1 = " << std::boolalpha << V1::hasGetMethod<foo1>::value << std::endl;
    std::cout << "V1. foo2 = " << std::boolalpha << V1::hasGetMethod<foo2>::value << std::endl;

    std::cout << "V2. foo1 = " << std::boolalpha << V2::hasGetMethod<foo1>::value << std::endl;
    std::cout << "V2. foo2 = " << std::boolalpha << V2::hasGetMethod<foo2>::value << std::endl;

    std::cout << "V3. foo1 = " << std::boolalpha << V3::hasGetMethod<foo1>::value << std::endl;
    std::cout << "V3. foo2 = " << std::boolalpha << V3::hasGetMethod<foo2>::value << std::endl;

    std::cout << "V4. foo1 = " << std::boolalpha << V4::hasGetMethod<foo1>() << std::endl;
    std::cout << "V4. foo2 = " << std::boolalpha << V4::hasGetMethod<foo2>() << std::endl;

    return 0;
}
