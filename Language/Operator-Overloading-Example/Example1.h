#pragma once

#include <iostream>
#include <cmath>

/*
 *
 * Пример перегрузки математических операторов:
 * - Базовые операторы: +, -, *, /
 * - Составные операторы присваивания: +=, -=, *=, /=
 * - Увеличение и уменьшение: --, ++
 * - Унарный оператор: - (отрицание)
 * - Операторы сравнения: ==, !=, <, >, <=, >=
 * - Операторы ввода/вывода: <<, >>
 */

namespace Example1 {

class Vector
{
private:
    double x, y, z;

public:
    Vector() : x(0), y(0), z(0) {}
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Сеттеры
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    // Вывод вектора
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    // Длина вектора
    double magnitude() const{
        return std::sqrt(x * x + y * y + z * z);
    }

    // Нормализация вектора
    Vector normalize() const {
        double mag = magnitude();
        if (mag == 0) return Vector();
        return Vector(x/mag, y/mag, z/mag);
    }

    // Перегрузка операторов

    // Сложение векторов
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // Вычитание векторов
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // Умножение на скаляр (справа)
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    // Умножение на скаляр (слева) - дружественная функция
    friend Vector operator*(double scalar, const Vector& vec) {
        return vec * scalar;
    }

    // Деление на скаляр
    Vector operator/(double scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }

        return Vector(x / scalar, y / scalar, z / scalar);
    }

    // Скалярное произведение
    double operator*(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Векторное произведение
    Vector cross(const Vector& other) const {
        return Vector(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
            );
    }

    // Унарный минус
    Vector operator-() const {
        return Vector(-x, -y, -z);
    }

    // prefix increment и decrement
    Vector& operator++() {
        x += 1;
        y += 1;
        z += 1;

        return *this;
    }

    Vector& operator--() {
        x -= 1;
        y -= 1;
        z -= 1;

        return *this;
    }

    // postfix increment и decrement
    Vector operator++(int) {
        Vector old = *this;
        operator++();
        return old;
    }

    Vector operator--(int) {
        Vector old = *this;
        operator--();
        return old;
    }

    // Сравнение векторов
    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool operator>(const Vector& other) const {
        return x > other.x && y > other.y && z > other.z;
    }

    bool operator>=(const Vector& other) const {
        return x >= other.x && y >= other.y && z >= other.z;
    }

    bool operator<(const Vector& other) const {
        return x < other.x && y < other.y && z < other.z;
    }

    bool operator<=(const Vector& other) const {
        return x <= other.x && y <= other.y && z <= other.z;
    }

    // Составные операторы присваивания
    Vector& operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    Vector& operator-=(const Vector& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    Vector& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    Vector& operator/=(double scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }

        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        is >> vec.x >> vec.y >> vec.z;
        return is;
    }
};

void test()
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    // Сложение
    Vector sum = v1 + v2;
    std::cout << "v1 + v2 = " << sum << std::endl;

    // Вычитание
    Vector diff = v1 - v2;
    std::cout << "v1 - v2 = " << diff << std::endl;

    // Умножение на скаляр
    Vector scaled = v1 * 2.5;
    std::cout << "v1 * 2.5 = " << scaled << std::endl;

    // Умножение скаляра на вектор
    Vector scaled2 = 3.0 * v2;
    std::cout << "3.0 * v2 = " << scaled2 << std::endl;

    // Сравнение
    std::cout << "v1 == v2 = " << std::boolalpha << (v1 == v2) << std::endl;
    std::cout << "v1 != v2 = " << std::boolalpha << (v1 != v2) << std::endl;
    std::cout << "v1 > v2 = "  << std::boolalpha << (v1 > v2)  << std::endl;
    std::cout << "v1 < v2 = "  << std::boolalpha << (v1 < v2)  << std::endl;
    std::cout << "v1 >= v2 = " << std::boolalpha << (v1 >= v2) << std::endl;
    std::cout << "v1 <= v2 = " << std::boolalpha << (v1 <= v2) << std::endl;

    // Скалярное произведение
    double dot = v1 * v2;
    std::cout << "v1 * v2 (dot) = " << dot << std::endl;

    // Векторное произведение
    Vector cross = v1.cross(v2);
    std::cout << "v1 x v2 = " << cross << std::endl;

    // Длина вектора
    std::cout << "|v1| = " << v1.magnitude() << std::endl;

    // Нормализация
    Vector norm = v1.normalize();
    std::cout << "v1 normalized = " << norm << std::endl;

    // Составные операторы
    v1 += v2;
    std::cout << "v1 += v2: " << v1 << std::endl;
}

} // namespace Example1
