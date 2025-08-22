#include <iostream>
#include <algorithm>
#include <cstring>

/*
 * Small Object Optimization (SOO) — это техника оптимизации, используемая в C++ для избежания динамического выделения памяти для маленьких
 * объектов. Она особенно распространена в реализациях std::string (также известна как Short String Optimization - SSO) и std::function.
 * Суть SOO, Класс содержит:
 * - Буфер фиксированного размера внутри себя (как член данных)
 * - Когда объект маленький — он размещается в этом буфере
 * - Когда объект большой — используется динамическая память
 *
 */

template<typename T, size_t SmallSize = 16>
class SmallObjectOptimized {
private:
    // Союз для экономии памяти
    union {
        T* dynamic_data;        // Для больших объектов
        char small_data[SmallSize * sizeof(T)]; // Для маленьких объектов
    };

    size_t size_;
    size_t capacity_;
    bool is_small_; // Флаг: true если используем small_data

public:
    SmallObjectOptimized() : size_(0), capacity_(SmallSize), is_small_(true) {}

    ~SmallObjectOptimized() {
        clear();
    }

    // Добавление элемента
    void push_back(const T& value) {
        if (size_ == capacity_) {
            // Нужно увеличить capacity
            reallocate(capacity_ * 2);
        }

        if (is_small_) {
            // Размещаем в small_data
            new (small_data + size_ * sizeof(T)) T(value);
        } else {
            // Размещаем в dynamic_data
            new (dynamic_data + size_) T(value);
        }
        size_++;
    }

    // Доступ к элементам
    T& operator[](size_t index) {
        if (is_small_) {
            return *reinterpret_cast<T*>(small_data + index * sizeof(T));
        } else {
            return dynamic_data[index];
        }
    }

    const T& operator[](size_t index) const {
        if (is_small_) {
            return *reinterpret_cast<const T*>(small_data + index * sizeof(T));
        } else {
            return dynamic_data[index];
        }
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool is_small() const { return is_small_; }

    void clear() {
        // Вызываем деструкторы
        for (size_t i = 0; i < size_; ++i) {
            if (is_small_) {
                reinterpret_cast<T*>(small_data + i * sizeof(T))->~T();
            } else {
                dynamic_data[i].~T();
            }
        }

        // Освобождаем динамическую память если использовали
        if (!is_small_) {
            delete[] dynamic_data;
        }

        size_ = 0;
        capacity_ = SmallSize;
        is_small_ = true;
    }

private:
    void reallocate(size_t new_capacity) {
        T* new_data;
        bool new_is_small = (new_capacity <= SmallSize);

        if (new_is_small) {
            new_data = reinterpret_cast<T*>(small_data);
        } else {
            new_data = new T[new_capacity];
        }

        // Переносим существующие данные
        for (size_t i = 0; i < size_; ++i) {
            T* source;
            if (is_small_) {
                source = reinterpret_cast<T*>(small_data + i * sizeof(T));
            } else {
                source = &dynamic_data[i];
            }

            new (&new_data[i]) T(std::move(*source));
            source->~T();
        }

        // Освобождаем старую динамическую память если была
        if (!is_small_) {
            delete[] dynamic_data;
        }

        // Обновляем состояние
        if (!new_is_small) {
            dynamic_data = new_data;
        }

        capacity_ = new_capacity;
        is_small_ = new_is_small;
    }
};

int main()
{
    // Пример с int
    SmallObjectOptimized<int, 4> int_container;

    std::cout << "Initially small: " << std::boolalpha << int_container.is_small() << std::endl;

    // Добавляем элементы - остаемся в small buffer
    for (int i = 0; i < 4; ++i) {
        int_container.push_back(i);
        std::cout << "Added " << i << ", still small: " << int_container.is_small() << std::endl;
    }

    // Переходим к динамической памяти
    int_container.push_back(4);
    std::cout << "After adding 5th element, small: " << int_container.is_small() << std::endl;

    // Пример с std::string
    SmallObjectOptimized<std::string, 2> string_container;

    string_container.push_back("short");
    std::cout << "Short string, small: " << string_container.is_small() << std::endl;

    string_container.push_back("another short");
    std::cout << "Two strings, small: " << string_container.is_small() << std::endl;

    // Длинная строка может вызвать переход
    string_container.push_back("very long string that might cause reallocation");
    std::cout << "After long string, small: " << string_container.is_small() << std::endl;

    return 0;
}
