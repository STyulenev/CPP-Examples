#pragma once

#include <memory>
#include <iostream>
#include <chrono>
#include <ctime>

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using uptr = std::unique_ptr<T>;

// Создание алиасов, для умных указателей
#define DCL_PTR_ALIAS(NAME)    \
using NAME##SPtr = sptr<NAME>; \
using NAME##UPtr = uptr<NAME>;



// Создание Forward declaration для PIMPLE и т.д.
#define FWD_DCL(NAME) \
    class NAME;       \
    DCL_PTR_ALIAS(NAME)



// Запрет на копирование объектов класса (удаление конструктора копирования и копирующего оператора присваивания)
#define DISABLE_CLASS_COPY(NAME) \
    NAME(const NAME&) = delete;  \
    NAME& operator=(const NAME&) = delete;



// Запрет на перемещение объектов класса (удаление конструктора перемещения и перемещающего оператора присваивания)
#define DISABLE_CLASS_MOVE(NAME) \
    NAME(const NAME&&) = delete;  \
    NAME& operator=(const NAME&&) = delete;



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



// Функция определения максимального значения
#define MAX(a, b) ({decltype(a) _a = (a); decltype(b) _b = (b); _a > _b ? _a : _b; })



// Пример лога
#define PROGRAMM_LOG(text) std::cout << "line: " <<__LINE__ << ", function: " << __FUNCTION__ << ", log: " << text << std::endl
