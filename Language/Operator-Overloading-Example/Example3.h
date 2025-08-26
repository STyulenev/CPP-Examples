#pragma once

#include <iostream>
#include <string>
#include <sstream>

/*
 *
 * Пример перегрузки операторов преобразования:
 * - explicit operator bool() - явное преобразование в bool
 * - explicit operator int() - явное преобразование в int
 * - operator double() - неявное преобразование в double
 * - explicit operator std::string() - явное преобразование в string
 * - operator const char*() - преобразование в C-строку
 * - explicit operator long() - явное преобразование в long
 * - operator float() - неявное преобразование в float
 */

namespace Example3 {

class SmartNumber {
private:
    double value;
    std::string name;

public:
    // Конструкторы
    SmartNumber() : value(0), name("unnamed") {}
    SmartNumber(double val, const std::string& n = "unnamed")
        : value(val), name(n) {}

    // Геттеры и сеттеры
    double getValue() const { return value; }
    void setValue(double val) { value = val; }

    const std::string& getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    // Арифметические операции для демонстрации
    SmartNumber operator+(const SmartNumber& other) const {
        return SmartNumber(value + other.value, name + "+" + other.name);
    }

    SmartNumber operator*(const SmartNumber& other) const {
        return SmartNumber(value * other.value, name + "*" + other.name);
    }

    // Операторы сравнения
    bool operator==(const SmartNumber& other) const {
        return value == other.value;
    }

    bool operator!=(const SmartNumber& other) const {
        return value != other.value;
    }

    // ОПЕРАТОРЫ ПРЕОБРАЗОВАНИЯ

    // 1. Преобразование в bool (explicit для безопасности)
    explicit operator bool() const {
        // Возвращаем true если значение не ноль
        return value != 0.0;
    }

    // 2. Преобразование в int (explicit)
    explicit operator int() const {
        // Округляем до ближайшего целого
        return static_cast<int>(value + 0.5 * (value >= 0 ? 1 : -1));
    }

    // 3. Преобразование в double (неявное)
    operator double() const {
        return value;
    }

    // 4. Преобразование в std::string (explicit)
    explicit operator std::string() const {
        std::ostringstream oss;
        oss << name << "=" << value;
        return oss.str();
    }

    // 5. Преобразование в C-style строку (для демонстрации)
    operator const char*() const {
        // Внимание: это потенциально опасно, так как возвращаем временный объект
        // На практике лучше использовать std::string
        static thread_local std::string temp;
        temp = std::to_string(value) + " (" + name + ")";
        return temp.c_str();
    }

    // 6. Преобразование в long (explicit)
    explicit operator long() const {
        return static_cast<long>(value);
    }

    // 7. Преобразование в float (неявное)
    operator float() const {
        return static_cast<float>(value);
    }

    // Методы для проверки условий
    bool isInteger() const {
        return value == static_cast<int>(value);
    }

    bool isPositive() const {
        return value > 0;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const SmartNumber& sn) {
        os << sn.name << " = " << sn.value;
        return os;
    }
};

// Дополнительные функции для демонстрации
void processBool(bool condition) {
    std::cout << "Bool condition: " << (condition ? "true" : "false") << std::endl;
}

void processInt(int number) {
    std::cout << "Integer: " << number << std::endl;
}

void processDouble(double number) {
    std::cout << "Double: " << number << std::endl;
}

void processString(const std::string& text) {
    std::cout << "String: " << text << std::endl;
}

void processCString(const char* text) {
    std::cout << "C-string: " << text << std::endl;
}

void test()
{
    std::cout << "=== Демонстрация операторов преобразования ===" << std::endl;

    SmartNumber num1(3.7, "num1");
    SmartNumber num2(0.0, "num2");
    SmartNumber num3(-2.5, "num3");
    SmartNumber num4(10.0, "num4");

    std::cout << "Созданные числа:" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    std::cout << num4 << std::endl;

    std::cout << "\n=== 1. Преобразование в bool (explicit) ===" << std::endl;
    // Явное преобразование обязательно
    if (static_cast<bool>(num1)) {
        std::cout << num1.getName() << " is truthy" << std::endl;
    }

    if (!static_cast<bool>(num2)) {
        std::cout << num2.getName() << " is falsy" << std::endl;
    }

    // Использование в условиях (неявное преобразование работает для условий)
    if (num1) {
        std::cout << num1.getName() << " is true in condition" << std::endl;
    }

    // Передача в функцию
    processBool(static_cast<bool>(num3));

    std::cout << "\n=== 2. Преобразование в int (explicit) ===" << std::endl;
    int intValue = static_cast<int>(num1);
    std::cout << num1.getName() << " as int: " << intValue << std::endl;

    processInt(static_cast<int>(num4));

    std::cout << "\n=== 3. Преобразование в double (неявное) ===" << std::endl;
    double doubleValue = num1; // Неявное преобразование
    std::cout << num1.getName() << " as double: " << doubleValue << std::endl;

    processDouble(num3); // Неявное преобразование

    std::cout << "\n=== 4. Преобразование в std::string (explicit) ===" << std::endl;
    std::string strValue = static_cast<std::string>(num1);
    std::cout << num1.getName() << " as string: " << strValue << std::endl;

    processString(static_cast<std::string>(num4));

    std::cout << "\n=== 5. Преобразование в const char* ===" << std::endl;
    processCString(num2); // Неявное преобразование

    std::cout << "\n=== 6. Преобразование в long (explicit) ===" << std::endl;
    long longValue = static_cast<long>(num4);
    std::cout << num4.getName() << " as long: " << longValue << std::endl;

    std::cout << "\n=== 7. Преобразование в float (неявное) ===" << std::endl;
    float floatValue = num1;
    std::cout << num1.getName() << " as float: " << floatValue << std::endl;

    std::cout << "\n=== Использование в выражениях ===" << std::endl;
    // Автоматическое преобразование в double в арифметических выражениях
    double result = double(num1) + 5.0; // num1 неявно преобразуется в double
    std::cout << num1.getName() << " + 5.0 = " << result << std::endl;

    // Сравнение с другими типами
    if (bool(num4) == 10.0) { // Неявное преобразование num4 в double
        std::cout << num4.getName() << " equals 10.0" << std::endl;
    }

    std::cout << "\n=== Проверка методов ===" << std::endl;
    std::cout << num1.getName() << " is integer: " << num1.isInteger() << std::endl;
    std::cout << num4.getName() << " is integer: " << num4.isInteger() << std::endl;
    std::cout << num3.getName() << " is positive: " << num3.isPositive() << std::endl;

    std::cout << "\n=== Составные выражения ===" << std::endl;
    SmartNumber complex = num1 * num4 + SmartNumber(2.0, "constant");
    std::cout << "Complex expression: " << complex << std::endl;

    // Преобразование результата
    std::cout << "As string: " << static_cast<std::string>(complex) << std::endl;
    std::cout << "As int: " << static_cast<int>(complex) << std::endl;
}

} // namespace Example3
