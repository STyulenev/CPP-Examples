#pragma once

/*
 * Класс-обёртка Node представляет собой единичный элемент односвязного списка,
 * содержит данные и указатель на следующий элемент.
 */
template<typename Type>
class Node
{
public:
    Type data;
    Node* next;

public:
    Node(Type data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Реализация односвязного списка
 */
template<typename Type>
class OneLinkedList
{
public:
    Node<Type>* head; // Указатель на первый элемент
    Node<Type>* tail; // Указатель на последний элемент

public:
    /*
     * Конструктор, первый и последний элемент указывают на nullptr
     */
    OneLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    /*
     * Деструктор, очищаем список в цикле
     */
    ~OneLinkedList() {
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

        // Если элемент один в списке
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        // Иначе удаляем первый и выставляем начало спсика на второй
        Node<Type>* node = head;
        head = node->next;
        delete node;
    }

    /*
     * Добавление элемента в конец списка
     */
    void push_back(Type data) {
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
    }

    /*
     * Добавление элемента в начало списка
     */
    void push_front(Type data) {
        // Создаём узел
        Node<Type>* node = new Node<Type>(data);
        // Первый элемент становится вторым
        node->next = head;
        // Созданный узел становится первым
        head = node;

        // Если список был пуст, то указываем tail на node
        if (tail == nullptr)
            tail = node;
    }

    /*
     * Удаление элемента в конце списка
     */
    void pop_back() {
        // Если список пуст, выходим
        if (tail == nullptr)
            return;

        // Если элемент один, обнуляем его и выходим
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        // Иначе идём до конца списка в цикле, чтобы найти предпоследний элемент
        Node<Type>* node = head;
        for (; node->next != tail; node = node->next);

        // Обнуляем последний и указываем tail на новый последний элемент
        node->next = nullptr;
        delete tail;
        tail = node;
    }

    /*
     * Получить элемент по индексу. Не типичный метод для списков.
     */
    Node<Type>* at(int index) {
        // Индекс не может быть отрицательным
        if (index < 0)
            return nullptr; // или throw std::out_of_range

        // Поиск поэлементный
        Node<Type>* node = head;
        int _index = 0;
        while (node && _index != index && node->next) {
            node = node->next;
            _index++;
        }

        // Если нашли элемент (_index == index), то возвращаем его, иначе nullptr
        return (_index == index) ? node : nullptr; // или throw std::out_of_range
    }

    /*
     * Вставка элемента следующим после элемента с индексом index.
     */
    void insert(int index, Type data) {
        // Ищем элемент по текущему индексу
        Node<Type>* left = at(index);
        if (left == nullptr)
            return; // или throw std::out_of_range

        // Получаем указатель на следующий элемент
        Node<Type>* right = left->next;
        // Создаём узел
        Node<Type>* node = new Node<Type>(data);

        // Вставляем новый элемент между ними
        left->next = node;
        node->next = right;

        // Если элемент стал последним, то указываем tail на новый последний элемент
        if (right == nullptr)
            tail = node;
    }

    /*
     * Удаление элемента по индексу.
     */
    void erase(int index) {
        // Индекс не может быть отрицательным
        if (index < 0)
            return; // или throw std::out_of_range

        // Если индекс равен нулю, то вставляем первым элементом
        if (index == 0) {
            pop_front();
            return;
        }

        // Ищем предыдущий элемент
        Node<Type>* left = at(index - 1);
        // Устанавливаем узел как следующий элемент от найденого (т.е. текущий)
        Node<Type>* node = left->next;

        // Проверка на выход за пределы списка
        if (node == nullptr)
            return; // или throw std::out_of_range

        // Устанавливаем указатель на следующий элемент после удаляемого
        Node<Type>* right = node->next;

        // Предыдущий теперь должен указывать на следующий (вырвали удаляемый элемент из цепочки)
        left->next = right;

        // Если элемент был последним, то указываем tail на новый последний элемент
        if (node == tail)
            tail = left;

        // Удаляем узел
        delete node;
    }
};
