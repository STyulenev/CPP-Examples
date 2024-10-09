#include "SomeClass.h"

#include <algorithm>
#include <cstring>
#include <iostream>

/*
 * Класс-счётчик (интрузивны, т.е вне класса) ссылок для класса SomeClass
 */
class SomeClassReferenceCount {
    friend class SomeClass;

    friend std::ostream &operator<<(std::ostream& out, SomeClassReferenceCount const& str) {
        out << "[" << str.data_ << ", " << str.count_ << "]";
        return out;
    }

public:
    SomeClassReferenceCount(const char *s) : count_(1) {
        strcpy(data_ = new char[strlen(s) + 1], s);
    }

    ~SomeClassReferenceCount() {
        delete[] data_;
    }

private:
    int count_;
    char* data_;

};

SomeClass::SomeClass() :
    reference(new SomeClassReferenceCount(""))
{
    std::cout << "Empty constructor: " << *reference << std::endl;
}

SomeClass::SomeClass(const SomeClass& someClass) :
    reference(someClass.reference)
{
    reference->count_++;
    std::cout << "Copy constructor" << *reference << std::endl;
}

SomeClass::SomeClass(const char* someClass) :
    reference(new SomeClassReferenceCount(someClass))
{
    std::cout << "Full constructor: " << *reference << std::endl;
}

SomeClass &SomeClass::operator=(const SomeClass& someClass)
{
    std::cout << "Step 1 Copy operator=: " << *someClass.reference << " to " << *reference << std::endl;
    SomeClass(someClass).swap(*this);
    std::cout << "Step 2 Copy operator=: " << *someClass.reference << " , " << *reference << std::endl;
    return *this;
}

SomeClass::~SomeClass()
{
    if (reference && --reference->count_ <= 0) {
        std::cout << "Decrease: " << *reference << std::endl;
        delete reference;
    }
}

void SomeClass::swap(SomeClass& someClass) throw()
{
    std::swap(this->reference, someClass.reference);
}
