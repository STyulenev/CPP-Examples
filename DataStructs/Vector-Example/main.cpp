#include <iostream>

#include "Vector.h"

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
    Vector<SomeClass> vector(5);

    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;

    vector.pushBack(SomeClass(10));
    vector.pushBack(SomeClass(20));
    vector.pushBack(SomeClass(30));
    vector.pushBack(SomeClass(40));
    vector.pushBack(SomeClass(50));
    vector.pushBack(SomeClass(60));
    vector.pushBack(SomeClass(70));

    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
    std::cout << "Elements present in vector: ";

    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i].getData() << " ";
    }

    std::cout << std::endl;

    vector.popFront();
    vector.popBack();

    std::cout << "Size: " << vector.size() << " Capacity: " << vector.capacity() << std::endl;
    std::cout << "Elements present in vector: ";

    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i].getData() << " ";
    }

    std::cout << std::endl;

    return 0;
}
