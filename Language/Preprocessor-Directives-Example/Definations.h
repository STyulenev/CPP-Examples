#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <span>

// Создание алиасов, для умных указателей
template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using uptr = std::unique_ptr<T>;

#define DCL_PTR_ALIAS(NAME)    \
using NAME##SPtr = sptr<NAME>; \
using NAME##UPtr = uptr<NAME>;
// ---------------------------------------------------------------------------------------------------------------


// Создание Forward declaration для PIMPLE и т.д.
#define FWD_DCL(NAME) \
    class NAME;       \
    DCL_PTR_ALIAS(NAME)
// ---------------------------------------------------------------------------------------------------------------


// Запрет на копирование объектов класса (удаление конструктора копирования и копирующего оператора присваивания)
#define DISABLE_CLASS_COPY(NAME) \
    NAME(const NAME&) = delete;  \
    NAME& operator=(const NAME&) = delete;
// ---------------------------------------------------------------------------------------------------------------


// Запрет на перемещение объектов класса (удаление конструктора перемещения и перемещающего оператора присваивания)
#define DISABLE_CLASS_MOVE(NAME) \
    NAME(const NAME&&) = delete;  \
    NAME& operator=(const NAME&&) = delete;
// ---------------------------------------------------------------------------------------------------------------


// Создание типового класса
#ifndef CREATE_TYPE_CLASS
#define CREATE_TYPE_CLASS(class_name)\
class class_name   \
{                  \
public:            \
    class_name();  \
    void doTask(); \
};
#endif
// ---------------------------------------------------------------------------------------------------------------


// Функция определения максимального значения
#define MAX(a, b) ({decltype(a) _a = (a); decltype(b) _b = (b); _a > _b ? _a : _b; })
// ---------------------------------------------------------------------------------------------------------------


// Пример лога
#define PROGRAMM_LOG(text) std::cout << "line: " <<__LINE__ << ", function: " << __FUNCTION__ << ", log: " << text << std::endl
// ---------------------------------------------------------------------------------------------------------------


// Пример создания enum и массива строк с возможность использования строк в конструкции ветвления switch
#define EVAL(...) __VA_ARGS__
#define VARCOUNT(...) \
EVAL(VARCOUNT_I(__VA_ARGS__,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,))
#define VARCOUNT_I(_,_26,_25,_24,_23,_22,_21,_20,_19,_18,_17,_16,_15,_14,_13,_12,_11,_10,_9,_8,_7,_6,_5,_4,_3,_2,X_,...) X_
#define GLUE(X,Y) GLUE_I(X,Y)
#define GLUE_I(X,Y) X##Y
#define FIRST(...) EVAL(FIRST_I(__VA_ARGS__,))
#define FIRST_I(X,...) X
#define TUPLE_TAIL(...) EVAL(TUPLE_TAIL_I(__VA_ARGS__))
#define TUPLE_TAIL_I(X,...) (__VA_ARGS__)

#define TRANSFORM(NAME_, ARGS_) (GLUE(TRANSFORM_,VARCOUNT ARGS_)(NAME_, ARGS_))
#define TRANSFORM_1(NAME_, ARGS_) NAME_ ARGS_
#define TRANSFORM_2(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_1(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_3(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_2(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_4(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_3(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_5(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_4(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_6(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_5(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_7(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_6(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_8(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_7(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_9(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_8(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_10(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_9(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_11(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_10(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_12(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_11(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_13(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_12(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_14(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_13(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_15(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_14(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_16(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_15(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_17(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_16(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_18(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_17(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_19(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_18(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_20(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_19(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_21(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_20(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_22(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_21(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_23(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_22(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_24(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_23(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_25(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_24(NAME_,TUPLE_TAIL ARGS_)
#define TRANSFORM_26(NAME_, ARGS_) NAME_(FIRST ARGS_),TRANSFORM_25(NAME_,TUPLE_TAIL ARGS_)
#define MAKE_INITIALIZER(...) { __VA_ARGS__ }

#ifndef STRINGIFY
#define STRINGIFY(X) STRINGIFY_I(X)
#define STRINGIFY_I(X) #X
#endif

#ifndef REGISTER_ENUM_VALUE
#define REGISTER_ENUM_VALUE(enum_name,...)\
static constexpr auto enum_name##AsStr = std::to_array<const char*>(EVAL( MAKE_INITIALIZER TRANSFORM(STRINGIFY, (UNDEFINED, __VA_ARGS__, MAX_VALUE))));
#endif

#ifndef REGISTER_ENUM
#define REGISTER_ENUM(enum_name,...)\
struct enum_name\
{\
    enum value_type\
    {\
        UNKNOWN = 0,\
         __VA_ARGS__,\
        MAX_VALUE\
     };\
    \
    static auto asStr(const enum_name::value_type _value)\
    {\
        if (_value > enum_name::MAX_VALUE || _value < enum_name::UNKNOWN)\
        {\
                return enum_name##AsStr.at(enum_name::UNKNOWN);\
        }\
            return enum_name##AsStr.at(_value);\
    };\
    \
    static auto fromStr(std::span<const char> _cstring)\
    {\
        std::string errStr(_cstring.data()); \
        auto it = std::find_if( std::begin(enum_name##AsStr),\
            std::end(enum_name##AsStr),\
            [&](const auto fstr) { return 0 == (errStr.compare(fstr)); });\
        if (it != enum_name##AsStr.end())\
        {\
            return static_cast<enum_name::value_type>(std::distance(std::begin(enum_name##AsStr), it));\
        }\
        return enum_name::value_type::UNKNOWN;\
    };\
};\
typedef enum_name::value_type T##enum_name;
#endif

#ifndef REGISTER_ENUM_AND_VALUE
#define REGISTER_ENUM_AND_VALUE(enum_name,...)\
REGISTER_ENUM_VALUE(enum_name,__VA_ARGS__)\
REGISTER_ENUM(enum_name,__VA_ARGS__)
#endif

#ifndef START_SWITCH
#define START_SWITCH(type)\
switch (type)\
{
#endif
#ifndef STOP_SWITCH
#define STOP_SWITCH \
default: break; \
}
#endif
// ---------------------------------------------------------------------------------------------------------------
