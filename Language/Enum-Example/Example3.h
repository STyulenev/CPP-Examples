#pragma once

#include <array>
#include <bitset>
#include <iostream>
#include <stdint.h>
#include <type_traits>

/*
 *
 * Примеры парсинга битового enum
 *
 */
namespace Example3
{

enum class Flags : uint32_t {
    None = 0x00,
    Flag1 = 0x01,
    Flag2 = 0x02,
    Flag3 = 0x03,
    Flag4 = 0x04,
    Flags1N2 = Flag1 | Flag2,
    // ...
    All = Flag1 | Flag2 | Flag3 | Flag4
};

// или

/*enum class Flags : uint32_t {
    None = 0,
    Flag1 = 1 << 0,
    Flag2 = 1 << 1,
    Flag3 = 1 << 2,
    Flag4 = 1 << 3,
    Flags1N2 = Flag1 | Flag2,
    // ...
    All = Flag1 | Flag2 | Flag3 | Flag4
};*/

Flags operator|(Flags a, Flags b)
{
    return static_cast<Flags>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

// Парсинг через std::underlying_type_t
namespace Ex1
{

void CheckFlags(Flags flags)
{
    using UnderlyingType = std::underlying_type_t<Flags>;
    UnderlyingType mask = 1;

    while (mask <= static_cast<UnderlyingType>(Flags::All))
    {
        if (static_cast<UnderlyingType>(flags) & mask)
        {
            std::cout << "Flag 0x" << std::hex << mask << " is set\n";
        }
        mask <<= 1;
    }
}


void test()
{
    Flags f = Flags::Flag1 | Flags::Flag3;
    CheckFlags(f);
}

} // namespace Ex1


// Через constexpr std::array
namespace Ex2
{

constexpr std::array<Flags, 4> AllFlags = {
    Flags::Flag1,
    Flags::Flag2,
    Flags::Flag3,
    Flags::Flag4
};

void CheckFlags(Flags flags)
{
    for (Flags flag : AllFlags)
    {
        if ((static_cast<uint32_t>(flags) & static_cast<uint32_t>(flag)) != 0)
        {
            std::cout << "Flag 0x" << std::hex << static_cast<uint32_t>(flag) << " is set\n";
        }
    }
}

void test()
{
    Flags f = Flags::Flag2 | Flags::Flag4;
    CheckFlags(f);
}

} // namespace Ex2


namespace Ex3
{

void CheckFlags(uint8_t flags)
{
    std::bitset<8> bits(flags);

    for (size_t i = 0; i < bits.size(); ++i)
    {
        if (bits.test(i))
        {
            std::cout << "Flag 0x" << std::hex << (1 << i) << " is set\n";
        }
    }
}

void test()
{
    Flags f = Flags::Flag2 | Flags::Flag4;
    CheckFlags(static_cast<uint8_t>(f));
}

} // namespace Ex3



// Пример сброса, установки и проверки флагов
namespace Ex4
{

// Шаблонная функция для проверки, является ли тип битовым enum
template <typename T>
concept BitmaskEnum = std::is_enum_v<T> && requires {
    { static_cast<std::underlying_type_t<T>>(T::All) }; // Должен быть определён `All` или аналогичный
};

// Проверка, установлен ли флаг
template <BitmaskEnum T>
constexpr bool HasFlag(T value, T flag)
{
    using U = std::underlying_type_t<T>;
    return (static_cast<U>(value) & static_cast<U>(flag)) != 0;
}

// Установка флага
template <BitmaskEnum T>
constexpr T SetFlag(T value, T flag)
{
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(value) | static_cast<U>(flag));
}

// Сброс флага
template <BitmaskEnum T>
constexpr T ClearFlag(T value, T flag)
{
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(value) & ~static_cast<U>(flag));
}

// Переключение флага (если был установлен — снимает, и наоборот)
template <BitmaskEnum T>
constexpr T ToggleFlag(T value, T flag)
{
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(value) ^ static_cast<U>(flag));
}

void test()
{
    Flags flags = Flags::Flag1;

    flags = SetFlag(flags, Flags::Flag2);
    std::cout << "Has Flag2: " << HasFlag(flags, Flags::Flag2) << "\n"; // 1 (true)

    flags = ClearFlag(flags, Flags::Flag2);
    std::cout << "Has Flag2: " << HasFlag(flags, Flags::Flag2) << "\n"; // 0 (false)

    flags = ToggleFlag(flags, Flags::Flag3);
    std::cout << "Has Flag3: " << HasFlag(flags, Flags::Flag3) << "\n"; // 1 (true)

}

} // namespace Ex4

} // namespace Example3
