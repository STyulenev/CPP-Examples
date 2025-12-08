#include "Example1.h"

namespace Example1 {

void test1()
{
    std::cout << "\ntest1()\n\n";

    std::cout << "1 + 2 = " << add(1, 2) << std::endl;
    std::cout << "1 or 2 = " << findMax<int>(1, 2) << std::endl;
    std::cout << "PI = " << PI << std::endl;
    //std::cout << "value1 = " << value1 << std::endl;
    std::cout << "value2 = " << value2 << std::endl;
}

} // namespace Example1
