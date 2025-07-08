#pragma once

#include <iostream>

/*
 *
 * Примеры стандартных макросов:
 * - __FILE__
 * - __LINE__
 * - __DATE__
 * - __TIME__
 * - __TIMESTAMP__
 */

namespace Example2 {

void test1()
{
    std::cout << "file: " << __FILE__ << ", line: " << __LINE__ << std::endl;
}

void test2()
{
    std::cout << "date: " << __DATE__ << ", time: " << __TIME__ << std::endl;
}

void test3()
{
    std::cout << "datetime: " << __TIMESTAMP__ << std::endl;
}

} // namespace Example2
