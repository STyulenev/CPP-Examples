#pragma once

#include <iostream>

/*
 * Скрытие имени в пространствах имён
 */

namespace Example3
{

namespace A { double x = 3.0; }
namespace B { using namespace A; int x = 5; } // здесь int x скрывает double x из A

void test()
{
    std::cout << "A::x = " << A::x << "\n";
    std::cout << "B::x = " << B::x << "\n";
}

} // namespace Example3
