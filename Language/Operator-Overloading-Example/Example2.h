#pragma once

#include <iostream>
#include <bitset>
#include <stdexcept>

/*
 *
 * Пример перегрузки битовых операторов:
 * - Базовые битовые операторы: &, |, ^, ~
 * - Операторы сдвига: <<, >>
 * - Составные операторы: &=, |=, ^=, <<=, >>=
 * - Оператор индексации: [] для доступа к отдельным битам
 * - Оператор преобразования: bool() для проверки на ненулевое значение
 */

namespace Example2 {

class BitSet
{
private:
    unsigned int data;
    static const int SIZE = 32; // 32 бита для unsigned int

public:
    // Конструкторы
    BitSet() : data(0) {}
    BitSet(unsigned int value) : data(value) {}

    // Геттер
    unsigned int getData() const { return data; }

    // Установка/получение отдельных битов
    void setBit(int pos, bool value) {
        if (pos < 0 || pos >= SIZE) {
            throw std::out_of_range("Bit position out of range");
        }
        if (value) {
            data |= (1 << pos);    // Установить бит
        } else {
            data &= ~(1 << pos);   // Сбросить бит
        }
    }

    bool getBit(int pos) const {
        if (pos < 0 || pos >= SIZE) {
            throw std::out_of_range("Bit position out of range");
        }
        return (data >> pos) & 1;
    }

    // Подсчет установленных битов
    int count() const {
        return std::bitset<SIZE>(data).count();
    }

    // Проверка на наличие установленных битов
    bool any() const { return data != 0; }
    bool none() const { return data == 0; }

    // Перегрузка битовых операторов

    // Побитовое И
    BitSet operator&(const BitSet& other) const {
        return BitSet(data & other.data);
    }

    // Побитовое ИЛИ
    BitSet operator|(const BitSet& other) const {
        return BitSet(data | other.data);
    }

    // Побитовое исключающее ИЛИ (XOR)
    BitSet operator^(const BitSet& other) const {
        return BitSet(data ^ other.data);
    }

    // Побитовое НЕ
    BitSet operator~() const {
        return BitSet(~data);
    }

    // Битовый сдвиг влево
    BitSet operator<<(int shift) const {
        return BitSet(data << shift);
    }

    // Битовый сдвиг вправо
    BitSet operator>>(int shift) const {
        return BitSet(data >> shift);
    }

    // Составные операторы присваивания
    BitSet& operator&=(const BitSet& other) {
        data &= other.data;
        return *this;
    }

    BitSet& operator|=(const BitSet& other) {
        data |= other.data;
        return *this;
    }

    BitSet& operator^=(const BitSet& other) {
        data ^= other.data;
        return *this;
    }

    BitSet& operator<<=(int shift) {
        data <<= shift;
        return *this;
    }

    BitSet& operator>>=(int shift) {
        data >>= shift;
        return *this;
    }

    // Операторы сравнения
    bool operator==(const BitSet& other) const {
        return data == other.data;
    }

    bool operator!=(const BitSet& other) const {
        return data != other.data;
    }

    // Оператор преобразования в bool (проверка на ненулевое значение)
    explicit operator bool() const {
        return data != 0;
    }

    // Оператор индексации
    bool operator[](int pos) const {
        return getBit(pos);
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const BitSet& bs) {
        for (int i = SIZE - 1; i >= 0; --i) {
            os << (bs.getBit(i) ? '1' : '0');
            if (i % 8 == 0 && i != 0) os << "'";
        }

        return os;
    }

    // Статические методы для создания масок
    static BitSet mask(int bits) {
        if (bits <= 0)
            return BitSet(0);

        if (bits >= SIZE)
            return BitSet(~0u);

        return BitSet((1u << bits) - 1);
    }

    static BitSet fromString(const std::string& binaryStr) {
        unsigned int value = 0;

        for (char c : binaryStr) {
            value <<= 1;
            if (c == '1') value |= 1;
            else if (c != '0') throw std::invalid_argument("Invalid binary string");
        }
        return BitSet(value);
    }
};

// Пример использования
void test()
{
    BitSet bs1(0b1101); // 13 в двоичной
    BitSet bs2(0b1011); // 11 в двоичной

    std::cout << "bs1: " << bs1 << " (decimal: " << bs1.getData() << ")" << std::endl;
    std::cout << "bs2: " << bs2 << " (decimal: " << bs2.getData() << ")" << std::endl;

    // Побитовые операции
    std::cout << std::endl << std::endl;
    std::cout << "bs1 & bs2: " << (bs1 & bs2) << " (AND)" << std::endl;
    std::cout << "bs1 | bs2: " << (bs1 | bs2) << " (OR)" << std::endl;
    std::cout << "bs1 ^ bs2: " << (bs1 ^ bs2) << " (XOR)" << std::endl;
    std::cout << "~bs1: " << (~bs1) << " (NOT)" << std::endl;

    // Битовые сдвиги
    std::cout << std::endl << std::endl;
    std::cout << "bs1 << 2: " << (bs1 << 2) << std::endl;
    std::cout << "bs2 >> 1: " << (bs2 >> 1) << std::endl;

    // Составные операторы
    std::cout << std::endl << std::endl;
    BitSet bs3 = bs1;
    bs3 |= bs2;
    std::cout << "bs1 |= bs2: " << bs3 << std::endl;

    bs3 = bs1;
    bs3 &= bs2;
    std::cout << "bs1 &= bs2: " << bs3 << std::endl;

    // Работа с отдельными битами
    std::cout << std::endl << std::endl;
    std::cout << "3-d bit bs1: " << bs1.getBit(3) << std::endl;

    BitSet bs4;
    bs4.setBit(0, true);
    bs4.setBit(2, true);
    bs4.setBit(4, true);
    std::cout << "bs4 with bits 0,2,4: " << bs4 << std::endl;

    // Оператор индексации
    std::cout << "bs4[2]: " << bs4[2] << std::endl;
    std::cout << "bs4[3]: " << bs4[3] << std::endl;

    // Подсчет битов
    std::cout << std::endl << std::endl;
    std::cout << "Set bits to bs1: " << bs1.count() << std::endl;
    std::cout << "bs1 any(): " << bs1.any() << std::endl;
    std::cout << "bs1 none(): " << bs1.none() << std::endl;

    // Преобразование в bool
    std::cout << std::endl << std::endl;
    if (bs1) {
        std::cout << "bs1 is not null" << std::endl;
    }

    // Создание масок
    std::cout << std::endl << std::endl;
    std::cout << "Mask 4 bits: " << BitSet::mask(4) << std::endl;

    // Из строки
    try {
        BitSet bs5 = BitSet::fromString("10101010");
        std::cout << "From string '10101010': " << bs5 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

} // namespace Example2
