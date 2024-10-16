#pragma once

#include <stdexcept>
#include <iostream>

/*
 * Класс-обёртка Node представляет собой единичный элемент двухсвязного списка,
 * содержит массив данных, указатель на предыдущий, следующий элемент и текущий размер.
 */
template<typename Type>
class Node {
public:
    Type*  _array; // Данные
    Node*  prev;   // Указатель на предыдущий элемент
    Node*  next;   // Указатель на следующий элемент
    size_t size;   // Текущий размер

    Node(const int capacity = 10) {
        _array = new Type[capacity];
        this->prev = nullptr;
        this->next = nullptr;
        size = 0;
    }

    ~Node() {
        delete[] _array;
    }

    void push_back(Type data) {
        _array[size] = data;
        size++;
    }

    void pop_back() {
        size--;
    }

    /*
     * Получение элемента по индексу
     */
    Type& at(const size_t index) {
        if (index >= 0 && index <= size && (this->_array + index) != nullptr)
            return *(this->_array + index);

        throw std::out_of_range("out from deque");
    }

    /*
     * Получение элемента по индексу
     */
    Type& operator[](const size_t index) {
        return at(index);
    }

};

/*
 * Реализация дека (а основе двухсвязного списка + массив в узле) ([][][][]) <=> ([][][][]) <=> ...
 */
template<typename Type>
class Deque
{
public:
    Node<Type>* head;   // Указатель на первый элемент
    Node<Type>* tail;   // Указатель на последний элемент
    int _capacity = 10; // Ёмкость массива данных в узле

public:
    /*
     * Конструктор, первый и последний элемент указывают на nullptr
     */
    Deque(const int capacity = 10) {
        if (capacity > 0 || capacity < INT32_MAX) {
            _capacity = capacity;
        } else {
            throw std::bad_array_new_length();
        }

        this->head = nullptr;
        this->tail = nullptr;
    }

    /*
     * Деструктор
     */
    ~Deque() {
        while (head != nullptr)
            pop_back();
    }

    void push_back(Type data) {
        // Если список пуст
        if (head == nullptr) {
            Node<Type>* node = new Node<Type>(_capacity);
            node->push_back(data);

            head = node;
            node->prev = tail;
            tail = node;
        } else {
            // Проверяем массив узла на заполненость
            if (tail->size == _capacity) {
                Node<Type>* node = new Node<Type>(_capacity);
                node->push_back(data);
                tail->next = node;
                tail = node;
            } else {
                tail->push_back(data);
            }
        }
    }

    /*
     * Удаление элемента в конце списка
     */
    void pop_back() {
        // Если список пуст, выходим
        if (tail == nullptr)
            return;

        // Проверяем на единственный элемент в узле
        if (tail->size == 1) {
            Node<Type>* node = tail->prev;

            // Проверка на один узел в списке
            if (node != nullptr)
                node->next = nullptr; // Последний узел вырван из списка
            else
                head = nullptr; // Если node == nullptr, тогда список обнуляется

            // Удаляем узел
            delete tail;

            // Устанавливаем новый хвостовой узел или обнуляем при node == nullptr
            tail = node;
        } else {
            tail->pop_back(); // Удаляем элемент из массива
        }
    }

    /*
     * Получение элемента по индексу
     */
    Type& at(const size_t index) {
        // Поиск поэлементный, пока не дойдём до tail
        Node<Type>* node = head;

        int from = 0;
        int to = index / _capacity;

        while (from != to) {
            // Вышли за пределы
            if (node == nullptr)
                throw std::out_of_range("out from deque");

            // Следующий
            node = node->next;
            from++;
        }

        return node->at(index % _capacity);
    }

    /*
     * Получение элемента по индексу
     */
    Type& operator[](const size_t index) {
        return at(index);
    }

};
