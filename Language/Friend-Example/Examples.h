#pragma once

#include <iostream>

/*
 *
 * Bсе случаи использования:
 * - Friend функция
 * - Friend класс
 * - Friend метод другого класса
 * - Friend шаблонная функция
 * - Friend шаблонный класс
 * - Friend для перегруженных операторов
 * - Взаимные friend классы
 * - Friend с наследованием
 * - Friend для специализаций шаблонов:
 *    - Friend для всех специализаций шаблона
 *    - Friend для конкретной специализации
 *    - Friend для конкретной функции шаблона
 *    - Friend между шаблонными классами
 *    - Friend с внешними шаблонными функциями
 *
 * Важные особенности friend:
 * - Не транзитивный - если A friend B, и B friend C, то A НЕ friend C
 * - Не наследуемый - дружественные отношения не наследуются
 * - Не симметричный - если A friend B, это не значит что B friend A
 * - Не нарушает инкапсуляцию - доступ предоставляется явно и контролируемо
 * - Используйте осторожно - слишком много friend отношений могут нарушить архитектуру
 *
 * Ключевые моменты при работе с шаблонами:
 * - template<typename U> friend class Box; - friend для всех специализаций
 * - friend class SpecialAccess; - friend для конкретного класса
 * - friend void specificFunction(...); - friend для конкретной функции
 * - Специализации требуют явного объявления friend для каждой
 * - Доступ предоставляется только тем типам, которые явно указаны как friend
 * - Правильное использование friend с шаблонами требует внимания к деталям и понимания, какие именно специализации должны иметь доступ к private членам.
 *
 */

namespace Example1 { // ----------------------------------------------------------- Friend функция

class MyClass
{
private:
    int secret = 42;

    // Объявление friend функции
    friend void showSecret(const MyClass& obj);
};

// Определение friend функции
void showSecret(const MyClass& obj)
{
    std::cout << "Secret: " << obj.secret << std::endl; // Доступ к private
}

void test()
{
    MyClass obj;
    showSecret(obj); // Output: Secret: 42
}

} // namespace Example1



namespace Example2 { // ----------------------------------------------------------- Friend класс

class SecretKeeper
{
private:
    int secretNumber = 123;
    std::string secretMessage = "Hello Friend!";

    // Другой класс имеет полный доступ
    friend class BestFriend;
};

class BestFriend
{
public:
    void revealSecrets(const SecretKeeper& keeper)
    {
        std::cout << "Number: " << keeper.secretNumber << std::endl;
        std::cout << "Message: " << keeper.secretMessage << std::endl;
    }
};

void test()
{
    SecretKeeper _keeper;
    BestFriend _friend;
    _friend.revealSecrets(_keeper);
}

} // namespace Example2



namespace Example3 { // ----------------------------------------------------------- Friend метод другого класса

class BankAccount; // Предварительное объявление

class Auditor
{
public:
    void audit(const BankAccount& account);
};

class BankAccount
{
private:
    double balance = 1000.0;
    int pin = 1234;

    // Только метод audit класса Auditor имеет доступ
    friend void Auditor::audit(const BankAccount& account);
};

void Auditor::audit(const BankAccount& account)
{
    std::cout << "Balance: $" << account.balance << std::endl;
    std::cout << "PIN: " << account.pin << std::endl;
}

void test()
{
    BankAccount account;
    Auditor auditor;
    auditor.audit(account);
}

} // namespace Example3



namespace Example4 { // ----------------------------------------------------------- Friend шаблонная функция

template<typename T>
class Container
{
private:
    T data;

    // Friend шаблонная функция
    template<typename U>
    friend void showData(const Container<U>& container);
};

template<typename U>
void showData(const Container<U>& container)
{
    std::cout << "Data: " << container.data << std::endl;
}

void test()
{
    Container<int> intContainer;
    Container<std::string> strContainer;

    showData(intContainer);
    showData(strContainer);
}

} // namespace Example4



namespace Example5 { // ----------------------------------------------------------- Friend шаблонный класс

template<typename T>
class Matrix;

// Шаблонная функция для вывода
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

template<typename T>
class Matrix
{
private:
    T data[2][2] = {{1, 2}, {3, 4}};

    // Friend шаблонный оператор
    friend std::ostream& operator<< <T>(std::ostream& os, const Matrix<T>& matrix);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            os << matrix.data[i][j] << " "; // Доступ к private
        }
        os << std::endl;
    }
    return os;
}

void test()
{
    Matrix<int> mat;
    std::cout << mat;
}

} // namespace Example5



namespace Example6 { // ----------------------------------------------------------- Friend для перегруженных операторов

class Vector3D
{
private:
    double x, y, z;

public:
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Friend для оператора сложения
    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);

    // Friend для оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
};

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

void test()
{
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    std::cout << "v1 + v2 = " << (v1 + v2) << std::endl;
}

} // namespace Example6



namespace Example7 { // ----------------------------------------------------------- Взаимные friend классы

class B;

class A
{
private:
    int a_secret = 10;

    // Класс B friend класса A
    friend class B;

    // Метод для доступа к B
    void accessB(const B& b);

public:
    void access(const B& b)
    {
        accessB(b);
    }

};

class B
{
private:
    int b_secret = 20;

    // Класс A friend класса B
    friend class A;

    // Метод для доступа к A
    void accessA(const A& a)
    {
        std::cout << "A's secret: " << a.a_secret << std::endl;
    }

public:
    void access(const A& a)
    {
        accessA(a);
    }
};

void A::accessB(const B& b)
{
    std::cout << "B's secret: " << b.b_secret << std::endl;
}

void test()
{
    A a;
    B b;

    a.access(b);
    b.access(a);
}

} // namespace Example7



namespace Example8 { // ----------------------------------------------------------- Friend с наследованием

class Base
{
private:
    int base_secret = 100;
protected:
    int base_protected = 200;

    friend class FriendOfBase;
};

class Derived : public Base
{
private:
    int derived_secret = 300;
};

class FriendOfBase
{
public:
    void accessBase(Base& base)
    {
        std::cout << "Base secret: " << base.base_secret << std::endl;
        std::cout << "Base protected: " << base.base_protected << std::endl;
    }

    void accessDerived(Derived& derived)
    {
        // Имеет доступ только к Base части Derived
        std::cout << "Base part secret: " << derived.base_secret << std::endl;
        std::cout << "Base part protected: " << derived.base_protected << std::endl;

        // НЕТ доступа к derived_secret!
        // std::cout << derived.derived_secret << std::endl; // Ошибка
    }
};

void test()
{
    Base _base;
    Derived _derived;
    FriendOfBase _friend;

    _friend.accessBase(_base);
    _friend.accessDerived(_derived);
}

} // namespace Example8



namespace Example9 { // ----------------------------------------------------------- Friend для всех специализаций шаблона

template<typename T>
class Box
{
private:
    T content;

public:
    Box(T value) : content(value) {}

    // Friend для всех специализаций Box
    template<typename U>
    friend class Box;

    // Friend для внешнего класса
    friend class SpecialAccess;
};

class SpecialAccess
{
public:
    template<typename T>
    void peek(const Box<T>& box)
    {
        std::cout << "Content: " << box.content << std::endl;
    }
};

void test()
{
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);
    Box<std::string> strBox("Hello");

    SpecialAccess access;
    access.peek(intBox);     // ✓ Работает
    access.peek(doubleBox);  // ✓ Работает
    access.peek(strBox);     // ✓ Работает
}

} // namespace Example9



namespace Example10 { // ----------------------------------------------------------- Friend для конкретной специализации

// Предварительное объявление
template<typename T> class Box;
class SpecialAccess;

// Специализация для int
template<>
class Box<int>
{
private:
    int content;

public:
    Box(int value) : content(value) {}

    // Только SpecialAccess имеет доступ к Box<int>
    friend class SpecialAccess;
};

// Общий шаблон
template<typename T>
class Box
{
private:
    T content;

public:
    Box(T value) : content(value) {}
};

class SpecialAccess
{
public:
    void peekInt(const Box<int>& box)
    {
        std::cout << "Int content: " << box.content << std::endl; // ✓ Доступ есть
    }

    template<typename T>
    void peekOther(const Box<T>& box)
    {
        // std::cout << box.content << std::endl; // ✗ Ошибка: нет доступа
        std::cout << "No access to Box<T> where T != int" << std::endl;
    }
};

void test()
{
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);

    SpecialAccess access;
    access.peekInt(intBox);        // ✓ Работает
    access.peekOther(doubleBox);   // ✗ Нет доступа к content
}

} // namespace Example10



namespace Example11 { // ----------------------------------------------------------- Friend для конкретной функции шаблона

template<typename T>
class Container
{
private:
    T data;

public:
    Container(T value) : data(value) {}

    // Friend для конкретной функции
    friend void showIntData(const Container<int>& container);
};

// Только эта функция имеет доступ к Container<int>
void showIntData(const Container<int>& container)
{
    std::cout << "Int data: " << container.data << std::endl;
}

// Эта функция НЕ имеет доступа
template<typename T>
void showData(const Container<T>& container)
{
    // std::cout << container.data << std::endl; // ✗ Ошибка: нет доступа
    std::cout << "No access to Container<T>" << std::endl;
}

void test()
{
    Container<int> intContainer(100);
    Container<double> doubleContainer(2.71);

    showIntData(intContainer);   // ✓ Работает
    showData(intContainer);      // ✗ Нет доступа
    showData(doubleContainer);   // ✗ Нет доступа
}

} // namespace Example11



namespace Example12 { // ----------------------------------------------------------- Friend между шаблонными классами

template<typename T>
class Matrix;

template<typename T>
class Vector
{
private:
    T x, y;

public:
    Vector(T x, T y) : x(x), y(y) {}

    // Friend для Matrix с тем же типом T
    friend class Matrix<T>;
};

template<typename T>
class Matrix
{
private:
    T a, b, c, d;

public:
    Matrix(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {}

    Vector<T> transform(const Vector<T>& vec)
    {
        // Имеем доступ к private полям Vector<T>
        T newX = a * vec.x + b * vec.y;
        T newY = c * vec.x + d * vec.y;
        return Vector<T>(newX, newY);
    }
};

// Для вывода Vector нужен friend оператор
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
{
    // Нет доступа к private полям!
    // os << vec.x << ", " << vec.y;
    return os;
}

void test()
{
    Vector<int> vec(1, 2);
    Matrix<int> mat(2, 3, 4, 5);

    Vector<int> result = mat.transform(vec);
    std::cout << "Transformed vector: (" << result << ")" << std::endl;
}

} // namespace Example12



namespace Example13 { // ----------------------------------------------------------- Friend с внешними шаблонными функциями

template<typename T>
class Wrapper
{
private:
    T value;

public:
    Wrapper(T val) : value(val) {}

    // Friend для шаблонной функции
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Wrapper<U>& wrapper);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const Wrapper<U>& wrapper)
{
    os << "Wrapped value: " << wrapper.value; // ✓ Доступ есть
    return os;
}

void test()
{
    Wrapper<int> w1(42);
    Wrapper<std::string> w2("Hello");

    std::cout << w1 << std::endl; // Wrapped value: 42
    std::cout << w2 << std::endl; // Wrapped value: Hello
}

} // namespace Example13
