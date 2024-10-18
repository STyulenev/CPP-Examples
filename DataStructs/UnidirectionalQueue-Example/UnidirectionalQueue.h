#pragma once

#include <stdexcept>

/*
 * Класс-обёртка Node представляет собой единичный элемент очереди списка,
 * содержит данные, указатель на предыдущий и следующий элемент.
 */
template<typename Type>
class Node {
public:
    Type data;  // Данные
    Node* next; // Указатель на следующий элемент

public:
    Node(Type data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Реализация однонаправленной очереди (на основе односвязного списка). Отличается от односвязного списка
 * некоторыми ограничениями в методах, например, отсутствуют методы добаления в начало, удаление из конца списка и т.д.
 */
template<typename Type>
class UnidirectionalQueue
{
private:
    Node<Type>* head; // Указатель на первый элемент
    Node<Type>* tail; // Указатель на последний элемент
    int size = 0;

public:
    /*
     * Конструктор, первый и последний элемент указывают на nullptr
     */
    UnidirectionalQueue() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    /*
     * Деструктор, очищаем список в цикле
     */
    ~UnidirectionalQueue() {
        while (head != nullptr)
            pop();
    }

    /*
     * Удалить элемент с начала списка
     */
    Node<Type> pop() {
        // Проверка на пустоту
        if (head == nullptr)
            throw std::out_of_range("out from UnidirectionalQueue"); // or return nullptr;

        // Если элемент один в списке
        if (head == tail) {
            Node<Type>* node = tail;
            head = tail = nullptr;
            size--;
            return *node;
        }

        // Иначе удаляем первый и выставляем начало спсика на второй
        Node<Type>* node = head;
        head = node->next;
        size--;
        return *node;
    }

    /*
     * Добавление элемента в конец списка
     */
    void push(Type data) {
        // Создаём узел
        Node<Type>* node = new Node<Type>(data);

        // Проверка на пустоту
        if (head == nullptr)
            head = node;

        // Если элемент был один в списке (tail = node)
        if (tail != nullptr)
            tail->next = node;

        // Указываем tail на новый последний элемент
        tail = node;

        size++;
    }

    /*
     * Проверка на пустоту
     */
    bool isEmpty() {
        return (head == nullptr);
    }

    /*
     * Получить элемент по индексу. Не типичный метод для списков/очередей.
     */
    const Node<Type>* at(int index) {
        // Индекс не может быть отрицательным
        if (index < 0)
            throw std::out_of_range("out from UnidirectionalQueue");

        // Поиск поэлементный, пока не дойдём до tail
        Node<Type>* node = head;
        int _index = 0;
        while (node && _index != index && node->next) {
            node = node->next;
            _index++;
        }

        // Если нашли элемент (_index == index), то возвращаем его
        if (_index == index)
            return node;
        else
            throw std::out_of_range("out from UnidirectionalQueue"); // иначе выход за пределы
    }

    /*
     * Получить элемент по индексу через оператор []
     */
    const Node<Type>* operator[](int index) {
        return at(index);
    }

    int getSize() const {
        return size;
    }

};
