#include <iostream>

#include "UnidirectionalQueue.h"

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
    UnidirectionalQueue<SomeClass> unidirectionalQueue;

    unidirectionalQueue.push(SomeClass(1));
    unidirectionalQueue.push(SomeClass(2));
    unidirectionalQueue.push(SomeClass(3));
    unidirectionalQueue.push(SomeClass(4));
    unidirectionalQueue.push(SomeClass(5));

    for (int i = 0; i < unidirectionalQueue.getSize(); ++i) {
        std::cout << unidirectionalQueue[i]->data.getData() << " ";
    }

    std::cout << std::endl;

    if (!unidirectionalQueue.isEmpty())
        std::cout << "Pop: " << unidirectionalQueue.pop().data.getData() << std::endl;

    if (!unidirectionalQueue.isEmpty())
        std::cout << "Pop: " << unidirectionalQueue.pop().data.getData() << std::endl;

    for (int i = 0; i < unidirectionalQueue.getSize(); ++i) {
        std::cout << unidirectionalQueue[i]->data.getData() << " ";
    }

    std::cout << std::endl;

    return 0;
}
