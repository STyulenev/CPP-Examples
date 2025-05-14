#include "Example2.h"

#include "Example0.h"

extern int num;

extern void externalFunction();

// Extern сообщает компилятору, что он может повторно использовать другой экземпляр, а не создать новый в текущем расположении.
// В Example1.cpp уже создался данный экземпляр.
extern template void printType<int>();

namespace Example2 {

void test1()
{
    std::cout << "\nExample2::test1()\n";

    externalFunction();
}

void test2()
{
    std::cout << "\nExample2::test2()\n";

    std::cout << "num = " << num << std::endl;
}

void test3()
{
    printType<int>();
}

} // namespace Example2
