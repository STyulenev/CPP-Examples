#pragma once

#include <iostream>
#include <string>

/*
 * Пример оператора switch для работы со строками
 *
 * https://github.com/Efrit/str_switch/blob/master/str_switch.h
 */
namespace Example1
{

#ifndef SWITCH
#define SWITCH(str) \
    switch(s_s::str_hash_for_switch(str))
#endif

#ifndef CASE
#define CASE(str) \
    static_assert(s_s::str_is_correct(str) && (s_s::str_len(str) <= s_s::MAX_LEN),\
    "CASE string contains wrong characters, or its length is greater than 9");\
    case s_s::str_hash(str, s_s::str_len(str))
#endif

#ifndef DEFAULT
#define DEFAULT \
    default
#endif

namespace s_s
{
    typedef unsigned char uchar;
    typedef unsigned long long ullong;

    const uchar MAX_LEN = 9;
    const ullong N_HASH = static_cast<ullong>(-1);

    constexpr ullong raise_128_to(const uchar power)
    {
        return 1ULL << 7 * power;
    }

    constexpr bool str_is_correct(const char* const str)
    {
        return (static_cast<signed char>(*str) > 0) ? str_is_correct(str + 1) : (*str ? false : true);
    }

    constexpr uchar str_len(const char* const str)
    {
        return *str ? (1 + str_len(str + 1)) : 0;
    }

    constexpr ullong str_hash(const char* const str, const uchar current_len)
    {
        return *str ? (raise_128_to(current_len - 1) * static_cast<uchar>(*str) + str_hash(str + 1, current_len - 1)) : 0;
    }

    inline ullong str_hash_for_switch(const char* const str)
    {
        return (str_is_correct(str) && (str_len(str) <= MAX_LEN)) ? str_hash(str, str_len(str)) : N_HASH;
    }

    inline ullong str_hash_for_switch(const std::string& str)
    {
        return (str_is_correct(str.c_str()) && (str.length() <= MAX_LEN)) ? str_hash(str.c_str(), str.length()) : N_HASH;
    }
}

void test()
{
    std::string month = "january";
    std::string days;

    SWITCH (month)
    {
    CASE("february"):
        days = "28 or 29";
        break;
    CASE("april"):
    CASE("june"):
    CASE("september"):
    CASE("november"):
        days = "30";
        break;
    CASE("january"):
    CASE("march"):
    CASE("may"):
    CASE("july"):
    CASE("august"):
    CASE("october"):
    CASE("december"):
        days = "31";
        break;
    DEFAULT:
        days = "?";
        break;
    }

    std::cout << month << " has " << days << " days." << std::endl;
}

} // namespace Example1
