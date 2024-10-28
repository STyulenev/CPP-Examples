#pragma once

#include <type_traits>
#include <iterator>
#include <iostream>

class SomeClass
{
public:
    SomeClass();
    SomeClass(const int field);
    ~SomeClass();

    int getField() const;
    void setField(const int field);

    bool operator==(const SomeClass& rhs);

private:
    int field;

};

template<typename Type, typename = void>
struct is_container : std::false_type
{};

template<typename Type>
struct is_container<Type, std::void_t<
        typename Type::value_type,
        typename Type::size_type,
        typename Type::allocator_type,
        typename Type::iterator,
        typename Type::const_iterator,
        decltype(std::declval<Type>().size()),
decltype(std::declval<Type>().begin()),
decltype(std::declval<Type>().end()),
decltype(std::declval<Type>().cbegin()),
decltype(std::declval<Type>().cend())>> : std::true_type
{};

template<typename T>
struct is_pointer { static const bool value = false; };

template<typename T>
struct is_pointer<T*> { static const bool value = true; };

template<class MapType>
struct is_map_type : std::is_same<typename MapType::value_type, std::pair<const typename MapType::key_type, typename MapType::mapped_type>> {};

template <typename Type, typename = is_container<Type>>
void printContainer(const Type& container)
{
    std::cout << "Print: ";

    for (auto element : container) {
        if constexpr (is_pointer<decltype (element)>::value) {
            if (element)
                std::cout << element->getField() << " ";
        } else {
            std::cout << element.getField() << " ";
        }
    }

    std::cout << std::endl;
}

template <typename Type, typename = is_map_type<Type>>
void printMap(const Type& map)
{
    std::cout << "Print: ";

    for(const auto& [key, value] : map) {
        std::cout << "[" << key << "][" << value->getField() << "] ";
    }

    std::cout << std::endl;
}
