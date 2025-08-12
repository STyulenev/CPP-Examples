#pragma once

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>

/*
 * =======================================================================================================================================================================
 *                                                                Non-modifying sequence operations
 * =======================================================================================================================================================================
 *
 * Range adaptors:
 * - ranges::range_adaptor_closure
 * - views::all_t
 * - views::all
 * - ranges::ref_view
 * - ranges::owning_view
 * - ranges::as_rvalue_view
 * - views::as_rvalue
 * - ranges::filter_view
 * - views::filter
 * - ranges::transform_view
 * - views::transform
 * - ranges::take_view
 * - views::take
 * - ranges::take_while_view
 * - views::take_while
 * - ranges::drop_view
 * - views::drop
 * - ranges::drop_while_view
 * - views::drop_while
 * - ranges::join_view
 * - views::join
 * - ranges::join_with_view
 * - views::join_with
 * - ranges::lazy_split_view
 * - views::lazy_split
 * - ranges::split_view
 * - views::split
 * - ranges::concat_view
 * - views::concat
 * - views::counted
 * - ranges::common_view
 * - views::common
 * - ranges::reverse_view
 * - views::reverse
 * - ranges::as_const_view
 * - views::as_const
 * - ranges::elements_view
 * - views::elements
 * - ranges::keys_view
 * - views::keys
 * - ranges::values_view
 * - views::values
 * - ranges::enumerate_view
 * - views::enumerate
 * - ranges::zip_view
 * - views::zip
 * - ranges::zip_transform_view
 * - views::zip_transform
 * - ranges::adjacent_view
 * - views::adjacent
 * - ranges::adjacent_transform_view
 * - views::adjacent_transform
 * - ranges::chunk_view
 * - views::chunk
 * - ranges::slide_view
 * - views::slide
 * - ranges::chunk_by_view
 * - views::chunk_by
 * - ranges::stride_view
 * - views::stride
 * - ranges::cartesian_product_view
 * - views::cartesian_product
 * - ranges::cache_latest_view
 * - views::cache_latest
 * - ranges::to_input_view
 * - views::to_input
 *
 */

namespace Example1 {

struct MyClass
{
    int id;
    std::string name;
};

inline bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id == rhs.id && lhs.name == rhs.name;
}

inline bool operator>(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id > rhs.id;
}

inline bool operator<(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id < rhs.id;
}

inline bool operator>=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id >= rhs.id;
}

inline bool operator<=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.id <= rhs.id;
}

namespace RO1 { // ----------------------------------- range_adaptor_closure (для создания фильтров, которые можно использовать через |)

// Адаптер для сортировки
struct sort_fn : std::ranges::range_adaptor_closure<sort_fn>
{
    template<std::ranges::random_access_range R>
    auto operator()(R&& r) const
    {
        std::ranges::sort(r);
        return std::forward<R>(r);
    }

    template<std::ranges::random_access_range R>
    friend auto operator|(R&& r, const sort_fn& adaptor)
    {
        return adaptor(std::forward<R>(r));
    }
};

inline constexpr sort_fn sort;

// Адаптер для фильтрации четных чисел
struct filter_even_fn : std::ranges::range_adaptor_closure<filter_even_fn>
{
    template<std::ranges::viewable_range R>
    auto operator()(R&& r) const
    {
        return std::forward<R>(r) | std::views::filter([](const MyClass& el) {
                   return el.id % 2 != 0;
               });
    }

    template<std::ranges::viewable_range R>
    friend auto operator|(R&& r, const filter_even_fn& adaptor)
    {
        return adaptor(std::forward<R>(r));
    }
};

// глобальный экземпляр для удобного использования
inline constexpr filter_even_fn filter_even;

void test()
{
    std::vector<MyClass> v{
        { 3, "name3" },
        { 1, "name1" },
        { 2, "name2" },
        { 4, "name4" },
        { 6, "name6" },
        { 5, "name5" }
    };

    auto result = v | sort | filter_even;

    // Вывод результата
    for (const auto& el : result)
    {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    }
}

} // namespace RO1



namespace RO2 { // ----------------------------------- all_t ()

void test()
{

}

} // namespace RO2


namespace RO3 { // ----------------------------------- all (берёт все элементы)

void test()
{
    std::vector<MyClass> v{
        { 3, "name3" },
        { 1, "name1" },
        { 2, "name2" },
        { 4, "name4" },
        { 6, "name6" },
        { 5, "name5" }
    };

    for (const auto& el : std::views::all(v) /*| дополнительная фильтрация */)
    {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    }
}

} // namespace RO3



namespace RO9 { // ----------------------------------- filter (фильтрация)

void test()
{
    std::vector<MyClass> v{
        { 3, "name3" },
        { 1, "name1" },
        { 2, "name2" },
        { 4, "name4" },
        { 6, "name6" },
        { 5, "name5" }
    };

    auto even = [](const MyClass& el) {
        return el.id % 2 != 0;
    };

    for (const auto& el : v | std::views::filter(even))
    {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    }
}

} // namespace RO9



namespace RO11 { // ----------------------------------- transform (изменение)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto increase = [](MyClass& el) -> MyClass& {
        el.id++;

        return el;
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    std::ranges::for_each(v | std::views::transform(increase), show);
}

} // namespace RO11



namespace RO13 { // ----------------------------------- take (действие над первыми n элементами диапазона)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    std::ranges::for_each(v | std::views::take(2), show);
}

} // namespace RO13



namespace RO15 { // ----------------------------------- take_while (действие над первыми n элементами диапазона до певого попадающего под условие)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto while_not = [](const MyClass& el) -> bool {
        return el.name != "name3";
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    std::ranges::for_each(v | std::views::take_while(while_not), show);
}

} // namespace RO15



namespace RO17 { // ----------------------------------- drop (пропустить первые n элементов)

void test()
{
    std::vector<MyClass> v{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    std::ranges::for_each(v | std::views::drop(2), show);
}

} // namespace RO17



namespace RO27 { // ----------------------------------- concat (соединить два диапазона)

void test()
{
    std::vector<MyClass> v1{
        { 1, "name1" },
        { 2, "name2" },
        { 3, "name3" },
        { 4, "name4" }
    };

    std::vector<MyClass> v2{
        { 5, "name5" },
        { 6, "name6" },
        { 7, "name7" },
        { 8, "name8" }
    };

    auto show = [](const MyClass& el) {
        std::cout << "{ id: " << el.id << ", name: " << el.name << " }" << std::endl;
    };

    // C++ 23
    //std::ranges::for_each(std::views::concat(v1, v2), show);

    auto merged = std::views::single(v1) | std::views::join;
    auto merged_full = std::views::join(std::array{v1, v2});
    std::ranges::for_each(merged_full, show);
}

} // namespace RO27

} // namespace Example1
