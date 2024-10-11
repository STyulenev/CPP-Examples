#include <iostream>

#include "OneLinkedList.h"

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
    OneLinkedList<SomeClass> list;

    list.push_back(SomeClass(2));
    list.push_front(SomeClass(1));
    list.push_back(SomeClass(3));
    list.push_back(SomeClass(4));
    list.push_back(SomeClass(5));

    {
        auto element = list.at(0);
        std::cout << "list.at(0) = " << ((element != nullptr) ? element->data.getData() : 0) << std::endl;
    }

    {
        auto element = list[0];
        std::cout << "list[0] = " << ((element != nullptr) ? element->data.getData() : 0) << std::endl;
    }

    list.erase(1);
    list.insert(0, SomeClass(5));
    list.pop_front();

    for (auto node = list.head; node != nullptr; node = node->next) {
        std::cout << node->data.getData() << " ";
    }

    std::cout << std::endl;

    return 0;
}
