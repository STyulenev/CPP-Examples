#pragma once

#include <stdexcept>

/*
 * Класс-обёртка Node представляет собой единичный элемент двухсвязного списка,
 * содержит данные, указатель на предыдущий и следующий элемент.
 */
template<typename Type>
class Node {
public:
    Type data;  // Данные
    Node* prev; // Указатель на предыдущий элемент
    Node* next; // Указатель на следующий элемент

public:
    Node(Type data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

/*
 * Реализация двухсвязного списка
 */
template<typename Type>
class TwoLinkedList
{
public:
    Node<Type>* head; // Указатель на первый элемент
    Node<Type>* tail; // Указатель на последний элемент

public:
    /*
     * Конструктор, первый и последний элемент указывают на nullptr
     */
    TwoLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    /*
     * Деструктор, очищаем список в цикле
     */
    ~TwoLinkedList() {
        while (head != nullptr)
            pop_front();
    }

    /*
     * Удалить элемент с начала списка
     */
    void pop_front() {
        // Проверка на пустоту
        if (head == nullptr)
            return;

        // Получаем указатель на второй элемент
        Node<Type>* node = head->next;

        // Проверка на один элемент в списке
        if (node != nullptr)
            node->prev = nullptr; // Первый элемент вырван из списка
        else
            tail = nullptr; // Если node == nullptr, тогда список обнуляется

        // Удаляем узел
        delete head;

        // Устанавливаем новый головной узел или обнуляем при node == nullptr
        head = node;
    }

    /*
     * Удаление элемента в конце списка
     */
    void pop_back() {
        // Если список пуст, выходим
        if (tail == nullptr)
            return;

        // Получаем указатель на предпоследний элемент
        Node<Type>* node = tail->prev;

        // Проверка на один элемент в списке
        if (node != nullptr)
            node->next = nullptr; // Последний элемент вырван из списка
        else
            head = nullptr; // Если node == nullptr, тогда список обнуляется

        // Удаляем узел
        delete tail;

        // Устанавливаем новый хвостовой узел или обнуляем при node == nullptr
        tail = node;
    }

    /*
     * Добавление элемента в конец списка
     */
    void push_back(Type data) {
        // Создаём узел
        Node<Type>* node = new Node<Type>(data);

        // Устанавливаем хвостовой элемент предыдущим у node
        node->prev = tail;

        // Если список был не пуст, то текущий tail получает указатель на следующий
        if (tail != nullptr)
            tail->next = node;

        // Если список был пуст, то теперь головной элемент == node
        if (head == nullptr)
            head = node;

        // Новый хвостовой элемент
        tail = node;
    }

    /*
     * Добавление элемента в начало списка
     */
    void push_front(Type data) {
        // Создаём узел
        Node<Type>* node = new Node<Type>(data);

        // Устанавливаем головной элемент следующим у node
        node->next = head;

        // Если список был не пуст, то текущий head получает указатель на предыдущий
        if (head != nullptr)
            head->prev = node;

        // Если список был пуст, то теперь хвостовой элемент == node
        if (tail == nullptr)
            tail = node;

        // Новый головной элемент
        head = node;
    }

    /*
     * Получить элемент по индексу. Не типичный метод для списков.
     */
    Node<Type>* at(int index) {
        // Поиск поэлементный, пока не дойдём до tail
        Node<Type>* node = head;
        int _index = 0;
        while (_index != index) {
            // Вышли за пределы
            if (node == nullptr)
                throw std::out_of_range("out from TwoLinkedList");

            // Следующий
            node = node->next;
            _index++;
        }

        return node;
    }

    /*
     * Получить элемент по индексу через оператор []
     */
    Node<Type>* operator[](int index) {
        return at(index);
    }

    /*
     * Вставка элемента следующим после элемента с индексом index.
     */
    void insert(int index, Type data) {
        // Поиск элемента
        Node<Type>* right = at(index); // может быть throw std::out_of_range("out from OneLinkedList");

        // Если элемент последний
        if (right == nullptr) {
            push_back(data);
            return;
        }

        Node<Type>* left = right->prev;
        // Если элемент первый
        if (left == nullptr) {
            push_front(data);
            return;
        }

        // Если средний, то необходимо связать крайние
        Node<Type>* node = new Node<Type>(data);
        node->prev = left;
        node->next = right;
        left->next = node;
        right->prev = node;
    }

    /*
     * Удаление элемента по индексу.
     */
    void erase(int index) {
        // Поиск элемента
        Node<Type>* node = at(index); // может быть throw std::out_of_range("out from OneLinkedList");
        if (node == nullptr)
            return;

        // Если это первый
        if (node->prev == nullptr) {
            pop_front();
            return;
        }

        // Если это второй
        if (node->next == nullptr) {
            pop_back();
            return;
        }

        // Если средний, то необходимо связать крайние
        Node<Type>* left = node->prev;
        Node<Type>* right = node->next;
        left->next = right;
        right->prev = left;

        // Удаляем элемент
        delete node;
    }
};
