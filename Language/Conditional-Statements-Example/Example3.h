#pragma once

#include <iostream>

/*
 * Оператор switch
 */

namespace Example3 {

// Устройство Даффа
void test1()
{
    auto lambda = [](int* array, int value, size_t count) {
        if (count == 0) return;

        size_t n = (count + 7) / 8;  // количество групп по 8 элементов

        switch (count % 8) {
        case 0: do { *array++ = value;
        case 7:      *array++ = value;
        case 6:      *array++ = value;
        case 5:      *array++ = value;
        case 4:      *array++ = value;
        case 3:      *array++ = value;
        case 2:      *array++ = value;
        case 1:      *array++ = value;
        } while (--n > 0);
        }
    };

    const size_t SIZE = 20;
    int arr1[SIZE] = {0};

    for (size_t index = 0; index < SIZE; ++index)
    {
        std::cout << arr1[index] << " ";
    }
    std::cout << "\n";

    lambda(arr1, 42, SIZE);

    for (size_t index = 0; index < SIZE; ++index)
    {
        std::cout << arr1[index] << " ";
    }
    std::cout << "\n";
}

// Дополнительное вычисление внутри switch
void test2()
{
    auto status = []() -> int {
        return 1;
    };

    switch (auto result = status(); result) {
    case 0: std::cout << "0"; break;
    case 1: std::cout << "1"; break;
    case 2: std::cout << "2"; break;
    default:
        std::cout << "default";
        break;
    }
}

} // namespace Example3
