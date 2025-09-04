#include <iostream>
#include <memory>
#include <string>
#include <utility>

/*
 * Copy-on-Write (COW) — техника управления ресурсами в программировании на C++, которая позволяет откладывать копирование
 * объекта до его изменения. Также называется «копированием при записи» или «отложенным копированием». Цель: минимизировать
 * использование памяти и улучшить производительность, разделяя ресурсы до необходимости изменения.
 *
 * Ключевые особенности CoW:
 * - Ленивое копирование - данные копируются только при модификации
 * - Разделение данных - несколько объектов могут использовать одни данные
 * - Семантика значений - объекты ведут себя как независимые копии
 * - Экономия памяти - избегаем ненужных копий
 *
 * Преимущества:
 * - Эффективно для часто копируемых, редко изменяемых данных
 * - Уменьшает накладные расходыкопирования
 * - Прозрачно для пользователя
 *
 * Недостатки:
 * - Накладные расходы на проверки уникальности
 * - Потенциальные проблемы в многопоточных средах
 * - Может быть менее эффективно для часто изменяемых данных
 *
 * Эта идиома исторически использовался в реализации std::string в некоторых ранних реализациях STL, но в современных
 * стандартах от него в большинстве отказались из-за проблем в многопоточном программировании.
 *
 */


template<typename T>
class CowPtr {
private:
    std::shared_ptr<T> ptr;

    // Вспомогательная функция для обеспечения уникальности
    void detach() {
        if (ptr && !ptr.unique()) {
            ptr = std::make_shared<T>(*ptr);
        }
    }

public:
    // Конструкторы
    CowPtr() : ptr(std::make_shared<T>()) {}
    explicit CowPtr(const T& value) : ptr(std::make_shared<T>(value)) {}
    explicit CowPtr(T&& value) : ptr(std::make_shared<T>(std::move(value))) {}

    // Конструктор копирования - разделяем данные
    CowPtr(const CowPtr& other) : ptr(other.ptr) {}

    // Конструктор перемещения
    CowPtr(CowPtr&& other) noexcept : ptr(std::move(other.ptr)) {}

    // Оператор присваивания
    CowPtr& operator=(const CowPtr& other) {
        if (this != &other) {
            ptr = other.ptr;
        }
        return *this;
    }

    CowPtr& operator=(CowPtr&& other) noexcept {
        ptr = std::move(other.ptr);
        return *this;
    }

    // Константный доступ к данным (не вызывает копирования)
    const T& operator*() const {
        return *ptr;
    }
    const T* operator->() const {
        return ptr.get();
    }

    // Не константный доступ (вызывает копирование при необходимости)
    T& operator*() {
        detach();
        return *ptr;
    }

    T* operator->() {
        detach();
        return ptr.get();
    }

    // Проверка на уникальность владения
    bool is_unique() const {
        return ptr.unique();
    }

    // Получение количества ссылок
    long use_count() const {
        return ptr.use_count();
    }
};

// Пример использования с пользовательским классом
class StringData
{
private:
    std::string data;

public:
    StringData() = default;
    StringData(const std::string& str) : data(str) {}

    void append(const std::string& str) {
        data += str;
    }

    const std::string& get() const {
        return data;
    }

    size_t length() const {
        return data.length();
    }
};

// Специализированный класс для строк с CoW
class CowString
{
private:
    CowPtr<StringData> data;

public:
    CowString() = default;
    CowString(const std::string& str) : data(StringData(str)) {}

    // Чтение - без копирования
    char operator[](size_t index) const {
        return data->get()[index];
    }

    // Запись - с копированием при необходимости
    char& operator[](size_t index) {
        return const_cast<char&>(data->get()[index]);
    }

    void append(const std::string& str) {
        data->append(str);
    }

    const std::string& str() const {
        return data->get();
    }

    size_t length() const {
        return data->length();
    }

    bool is_unique() const {
        return data.is_unique();
    }

    long use_count() const {
        return data.use_count();
    }
};

int main()
{
    // Создаем первую строку
    CowString str1("Hello");
    std::cout << "str1: " << str1.str() << " (unique: " << str1.is_unique() << ", use_count: " << str1.use_count() << ")" << std::endl;

    // Копируем - данные разделяются
    CowString str2 = str1;
    std::cout << "After copying:" << std::endl;
    std::cout << "str1: " << str1.str() << " (unique: " << str1.is_unique() << ", use_count: " << str1.use_count() << ")" << std::endl;
    std::cout << "str2: " << str2.str() << " (unique: " << str2.is_unique() << ", use_count: " << str2.use_count() << ")" << std::endl;

    // Модифицируем str2 - происходит копирование
    str2.append(" World");
    std::cout << "\nAfter modification str2:" << std::endl;
    std::cout << "str1: " << str1.str() << " (unique: " << str1.is_unique() << ", use_count: " << str1.use_count() << ")" << std::endl;
    std::cout << "str2: " << str2.str() << " (unique: " << str2.is_unique() << ", use_count: " << str2.use_count() << ")" << std::endl;

    // Создаем еще одну копию
    CowString str3 = str1;
    std::cout << "\nAfter creating str3 from str1:" << std::endl;
    std::cout << "str1: " << str1.str() << " (unique: " << str1.is_unique() << ", use_count: " << str1.use_count() << ")" << std::endl;
    std::cout << "str3: " << str3.str() << " (unique: " << str3.is_unique() << ", use_count: " << str3.use_count() << ")" << std::endl;

    return 0;
}
