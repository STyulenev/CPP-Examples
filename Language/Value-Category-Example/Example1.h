#pragma once

#include <iostream>
#include <utility>
#include <string>

namespace Example1 {

// Вспомогательная функция для демонстрации
int createInt()
{
    return 42;
}

// Функция, возвращающая lvalue ссылку
int& getReference(int& x)
{
    return x;
}

// Функция, возвращающая rvalue ссылку
int&& getRvalueReference()
{
    return 42;
}

// Функция для демонстрации категорий
void processValue(int&& value)
{
    std::cout << "Processing rvalue: " << value << std::endl;
}

void processValue(int& value)
{
    std::cout << "Processing lvalue: " << value << std::endl;
}

class MyClass
{
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    MyClass(const MyClass&) { std::cout << "MyClass copied\n"; }
    MyClass(MyClass&&) { std::cout << "MyClass moved\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

MyClass createMyClass()
{
    return MyClass();
}

void test()
{
    // 1. LVALUE (lvalue) - имеет имя и адрес
    int x = 10;              // x - lvalue
    int arr[5] = {1, 2, 3};  // arr - lvalue
    std::string s = "hello"; // s - lvalue

    std::cout << "x = " << x << ", address: " << &x << std::endl;

    // 2. RVALUE (rvalue) - временные объекты, не имеют имени
    int y = x + 5;       // (x + 5) - rvalue
    int z = createInt(); // возвращаемое значение - rvalue

    std::cout << "y = " << y << std::endl;
    // &(x + 5); // Ошибка: нельзя взять адрес rvalue

    // 3. XVALUE (eXpiring value) - объекты, которые можно "перемещать"
    int a = 10;
    int b = std::move(a); // std::move(a) - xvalue

    MyClass obj1;
    MyClass obj2 = std::move(obj1); // std::move(obj1) - xvalue

    // 4. PRVALUE (pure rvalue) - чистые временные значения
    int prval1 = 42;      // 42 - prvalue
    double prval2 = 3.14; // 3.14 - prvalue
    MyClass obj3 = createMyClass(); // возвращаемое значение - prvalue

    // 5. GLVALUE (generalized lvalue) - lvalue или xvalue
    int glval = 100;
    int& ref = glval; // ref - glvalue (lvalue)
    int&& rref = std::move(glval); // rref - glvalue (xvalue)

    // Демонстрация перегрузок функций
    int test = 50;
    processValue(test);           // вызовет lvalue версию
    processValue(100);           // вызовет rvalue версию
    processValue(std::move(test)); // вызовет rvalue версию

    // 7. Категории в выражениях
    int i = 10;
    int j = 20;

    // i++ - rvalue (возвращает временное значение)
    // ++i - lvalue (возвращает сам объект)
    int k = i++; // i++ - prvalue
    int& m = ++j; // ++j - lvalue

    std::cout << "After i++: i = " << i << ", k = " << k << std::endl;
    std::cout << "After ++j: j = " << j << ", m = " << m << std::endl;

    // 8. Ссылки на разные категории
    int val = 100;

    int& lref = val;        // lvalue reference
    const int& clref = 200; // const lvalue reference может приравниваться к rvalue
    int&& rref2 = 300;      // rvalue reference

    std::cout << "lref: " << lref << ", clref: " << clref << ", rref2: " << rref2 << std::endl;
}

} // namespace Example1
