#pragma once

#include <vector>

class SomeClass
{
public:
    SomeClass();;
    SomeClass(const int field);
    ~SomeClass();

    int getField() const;

private:
    int field;

};

void prindSizeNCapacity(const std::vector<SomeClass*>& v);
void prindSizeNCapacity(const std::vector<SomeClass>& v);
void printVector(const std::vector<SomeClass*>& v);
