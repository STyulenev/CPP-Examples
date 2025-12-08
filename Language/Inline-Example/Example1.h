#pragma once

#include <iostream>

///*const*/int value1 = 42;        // Каждая единица трансляции получит свою копию, будет ошибка
inline /*const*/ int value2 = 42;  // Одно определение на всю программу

// Избежали многократного определения в Example1A.cpp и Example1B.cpp
inline int add(int a, int b) {
    return a + b;
}

// Избежали многократного определения в Example1A.cpp и Example1B.cpp
template <typename T>
inline T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Избежали многократного определения в Example1A.cpp и Example1B.cpp
inline const double PI = 3.14;

// Для оптимизации компилятором простых функций (делать их встроенными), но после C++98 компилятору уже не нужны такие подсказки.
inline int square(int x) {
    return x * x;
}

// Создание методов классов за его пределами
class MyClass
{
public:
    int getField() const;
    void setField(int newField);

private:
    int field;

};

inline int MyClass::getField() const
{
    return field;
}

inline void MyClass::setField(int newField)
{
    field = newField;
}

namespace Example1 {

void test1();
void test2();

inline void test3() // Избежали многократного определения
{
    std::cout << "\ntest3()\n\n";

    std::cout << "2 * 2 = " << square(2) << std::endl;
}

inline void test4() // Избежали многократного определения
{
    std::cout << "\ntest4()\n\n";

    MyClass myClass;
    myClass.setField(5);

    std::cout << "myClass.field = " << myClass.getField() << std::endl;
}

} // namespace Example1
