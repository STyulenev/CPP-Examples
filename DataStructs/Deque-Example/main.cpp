#include <iostream>

#include "Deque.h"

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
    Deque<int> deque(5);

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);
    deque.push_back(6);
    deque.push_back(7);

    deque.pop_back();

    std::cout << "deque.at(6) = " << deque.at(6) << std::endl;

    return 0;
}
