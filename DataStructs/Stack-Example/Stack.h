#pragma once

#include <stdexcept>

/*
 * Реализация стека
 */
template<typename Type>
class Stack
{
private:
    Type* _array = nullptr; // Массив с данными
    int   _capacity;        // Максимально возможный размер массива (ёмкость)
    int   _size;            // Индекс текущего элемента (верхний) т.е. текущий размер

public:
    /*
     * Конструктор с инициализацией массива
     */
    Stack(int capacity = 10) {
        if (capacity > 0 || capacity > INT32_MAX) {
            this->_capacity = capacity;
            _array = new Type[capacity];
            _size = -1;
        } else {
            throw std::bad_array_new_length();
        }
    }

    /*
     * Деструктор с очисткой массива
     */
    ~Stack() {
        clear();
    }

    /*
     * Метод добавляет новый элемент в стек
     */
    bool push(Type data)
    {
        // Проверка на переполнение
        if (_size >= _capacity) {
            recreation(); // or throw std::out_of_range("out from Stack"); / return false;
        }

        // Добавление нового элемент верхним в стек
        _array[++_size] = data;

        return true;
    }

    /*
     * Метод возвращает верхний элемент c удалением из стека
     */
    Type pop() {
        if (_size < 0) {
            throw std::out_of_range("out from Stack");
        }

        // Возвращаем элемент и уменьшаем размер
        return _array[_size--];
    }

    /*
     * Метод возвращает верхний элемент без удаления из стека
     */
    Type peek() {
        if (_size < 0) {
            throw std::out_of_range("out from Stack");
        }

        return _array[_size];
    }

    /*
     * Проверка на пустоту
     */
    bool isEmpty() {
        return (_size < 0);
    }

    /*
     * Полная очистка стека
     */
    void clear() {
        while (!this->isEmpty()) {
            this->pop();
        }

        _size = -1;
    }

    /*
     * Возвращает текущий размер
     */
    int size() const {
        return _size;
    }

    /*
     * Возвращает максимально возможный размер (ёмкость) до перезаписи
     * (если используется reсreation(), иначе до throw std::out_of_range("out from Stack") / return false)
     */
    int capacity() const {
        return _capacity;
    }

private:
    /*
     * Необязательный метод для стека - пересоздание массива с увеличенным в х2 размером
     */
    void recreation() {
        // Увеличиваем размер в х2
        int tempSize = _capacity * 2;

        // Проверяем на выход за пределы
        if (tempSize > INT32_MAX)
            tempSize = INT32_MAX;

        // Создаём новый массив
        Type* tempArray = new Type[tempSize];

        // Заполняем его текущими значениями
        for (int i = 0; i < _capacity; i++) {
            tempArray[i] = _array[i];
        }

        // Удаляем старый массив
        delete[] _array;

        // Меняем размер и массив на новые
        _array = tempArray;
        _capacity = tempSize;
    }

};
