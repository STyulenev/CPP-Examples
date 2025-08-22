#pragma once

#include <iostream>
#include <utility>

/*
 * Пример с передачей лямбды и последующим применением
 */

namespace Example2
{

// Функция, которую будем передавать
void print_hello() {
    std::cout << "Hello, World!" << std::endl;
}

void print_number(int x) {
    std::cout << "Number: " << x << std::endl;
}

// Шаблонная функция с perfect forwarding
template<typename Func, typename... Args>
void call_with_forwarding(Func&& func, Args&&... args)
{
    // Perfect forwarding функции и её аргументов
    std::forward<Func>(func)(std::forward<Args>(args)...);
}

void test()
{
    // Передача функции как lvalue
    call_with_forwarding(print_hello);

    // Передача лямбды как rvalue
    call_with_forwarding([](){ std::cout << "Lambda!" << std::endl; });

    // Передача функции с аргументами
    call_with_forwarding(print_number, 42);
}

} // namespace Example2
