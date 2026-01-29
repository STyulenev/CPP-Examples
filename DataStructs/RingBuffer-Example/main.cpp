#include <iostream>

#include "RingBuffer.h"

int main()
{
    RingBuffer<int, 5> ringBuffer;

    for (int i = 1; i <= ringBuffer.size(); ++i)
    {
        ringBuffer.push(i);
        std::cout << "rb.push(" << i << "): ";
        std::cout << "size = " << ringBuffer.size() << std::endl;
    }

    std::cout << "rb.full() ? " << (ringBuffer.full() ? "Yes" : "No") << std::endl;

    // Добавляем лишний элемент
    ringBuffer.push(6);
    std::cout << "rb.push(6): size = " << ringBuffer.size() << std::endl;

    // Очищаем буфер
    while (!ringBuffer.empty())
    {
        auto val = ringBuffer.pop();
        std::cout << "Poped: " << *val << std::endl;
    }

    // Попытка получение элемента из пустого буфера
    auto none = ringBuffer.pop();
    std::cout << "Trying to pop from empty buffer: " << (none.has_value() ? "Got value" : "Empty") << std::endl;

    return 0;
}
