#pragma once

#include <stdexcept>

/*
 * Реализация вектора
 */
template <typename Type>
class Vector
{
private:
    Type*  _array = nullptr; // Массив данных
    size_t _capacity;        // Максимально возможный размер массива (ёмкость)
    size_t _size;            // Текущий размер

public:
    /*
     * Конструктор с инициализацией массива
     */
    Vector(int capacity = 10) {
        if (capacity > 0 || capacity < INT32_MAX) {
            _capacity = capacity;
            _array = new Type[_capacity];
            _size = 0;
        } else {
            throw std::bad_array_new_length();
        }
    }

    /*
     * Деструктор с очисткой массива
     */
    ~Vector() {
        clear(); // or delete[] _array;
    }

    /*
     * Метод для добавления элемента в конец
     */
    void pushBack(const Type& data) {
        if (_capacity == _size) {
            recreation();
        }

        _array[_size] = data;
        _size++;
    }

    /*
     * Метод для удаления последнего элемента
     */
    void popBack() {
        if (isEmpty())
            return;

        _size--;
    }

    /*
     * Метод для удаления первого элемента
     */
    void popFront() {
        if (isEmpty())
            return;

        if (_size != 1) {
            std::swap(_array[_size - 1], _array[0]);
        }

        _size--;
    }

    /*
     * Проверка на пустоту
     */
    bool isEmpty() const {
        return _size == 0;
    }

    /*
     * Возвращает текущий размер
     */
    size_t size() const {
        return _size;
    }

    /*
     * Возвращает максимально возможный размер (ёмкость) до перезаписи
     */
    size_t capacity() const {
        return _capacity;
    }

    /*
     * Полная очистка вектора
     */
    void clear() {
        // Элементы нет смысла удалять, в дальнейшем произойдёт перезапись

        _size = 0;
    }

    /*
     * Получение элемента по индексу (без проверки)
     */
    Type& operator[](const size_t index) {
        return *(this->_array + index);
    }

    /*
     * Получение элемента по индексу (с проверкой)
     */
    Type& at(const size_t index) {
        if (index >= 0 && index <= _size)
            return *(this->_array + index);

        throw std::out_of_range("out from vector");
    }

private:
    void recreation() {
        // Увеличиваем размер в х2
        int tempCapacity = _capacity * 2;

        // Проверяем на выход за пределы
        if (tempCapacity > INT32_MAX)
            tempCapacity = INT32_MAX;

        // Создаём новый массив
        Type* tempArray = new Type[tempCapacity];

        // Заполняем его текущими значениями
        for (int i = 0; i < _size; i++) {
            tempArray[i] = _array[i];
        }

        // Удаляем старый массив
        delete[] _array;

        // Меняем размер и массив на новые
        _array = tempArray;
        _capacity = tempCapacity;
    }

};
