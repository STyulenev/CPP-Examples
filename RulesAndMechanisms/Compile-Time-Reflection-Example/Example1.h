#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <string_view>
#include <utility>

/*
 * Пример рефлексии времени выполнения для итерации по полям структур без ручного перечисления каждого поля.
 */

namespace Example1 {

template <class... Accessors>
class Field
{
public:
    constexpr Field(std::string_view name, Accessors... accessors) noexcept
        : name_{name}, accessors_{accessors...}
    {}

    constexpr std::string_view name() const noexcept { return name_; }

    template <class U>
    constexpr decltype(auto) extract_from(U& obj) const noexcept
    {
        return extract_impl(obj, std::index_sequence_for<Accessors...>{});
    }

private:
    template <class U, size_t... Is>
    constexpr decltype(auto) extract_impl(U& obj, std::index_sequence<Is...>) const noexcept
    {
        // Для одного аксессора - просто указатель на член
        if constexpr (sizeof...(Accessors) == 1)
        {
            return obj.*std::get<0>(accessors_);
        }
        else
        {
            return ((obj.*std::get<Is>(accessors_)), ...); // Упрощённо
        }
    }

    std::string_view name_;
    std::tuple<Accessors...> accessors_;
};

// Deduction guide
template <class... Accessors>
Field(std::string_view, Accessors...) -> Field<Accessors...>;

template <class... Fields>
class Schema
{
public:
    constexpr Schema(Fields... fields) noexcept
        : fields_{std::move(fields)...}
    {}

    template <class U, class Callable>
    constexpr void for_each(U& obj, Callable&& callable) const
    {
        for_each_impl(obj, std::forward<Callable>(callable),
                      std::index_sequence_for<Fields...>{});
    }

private:
    template <class U, class Callable, size_t... Is>
    constexpr void for_each_impl(U& obj, Callable&& callable,
                                 std::index_sequence<Is...>) const
    {
        (std::invoke(callable,
                     std::get<Is>(fields_).name(),
                     std::get<Is>(fields_).extract_from(obj)), ...);
    }

    std::tuple<Fields...> fields_;
};

// Deduction guide
template <class... Fields>
Schema(Fields...) -> Schema<Fields...>;

// Пример использования
struct Person
{
    std::string name;
    int age;

    static constexpr auto schema = Schema{
        Field{"name", &Person::name},
        Field{"age", &Person::age}
    };
};

void test()
{
    Person person{
        .name = "Alice",
        .age = 30
    };

    Person::schema.for_each(person,
                            [](std::string_view field_name, auto&& field_value)
                            {
                                std::cout << field_name << ": " << field_value << '\n';
                            }
                            );
}

} // namespace Example1
