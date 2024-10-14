#include <iostream>

#include "Stack.h"

class SomeClass
{
private:
    int data;

public:
    SomeClass(int data = 0) : data(data) {}
    ~SomeClass() {}

    int getData() const {
        return data;
    }
};

int main()
{
    Stack<SomeClass> stack(5);

    std::cout << "Size: " << stack.size() << " Capacity: " << stack.capacity() << std::endl;

    stack.push(SomeClass(10));
    stack.push(SomeClass(20));
    stack.push(SomeClass(30));
    stack.push(SomeClass(40));
    stack.push(SomeClass(50));
    stack.push(SomeClass(60));
    stack.push(SomeClass(70));
    stack.push(SomeClass(80));

    std::cout << "Size: " << stack.size() << " Capacity: " << stack.capacity() << std::endl;

    std::cout << "Top element is: " << stack.peek().getData() << std::endl;
    std::cout << "Elements present in stack: ";

    while (!stack.isEmpty()) {
        std::cout << stack.pop().getData() << " ";
    }

    std::cout << std::endl;

    return 0;
}
