#pragma once

#include <array>
#include <optional>

/*
 * Простая реализация шаблонного кольцевого буфера (циклического буфера).
 */
template <typename T, std::size_t Capacity>
class RingBuffer {
public:
    RingBuffer() = default;

    /*
     * Метод добавления нового элемента в буфер
     * Если буфер заполнен, самый старый элемент перезаписывается.
     */
    void push(const T& value) {
        m_buffer[m_head] = value;
        m_head = (m_head + 1) % Capacity;

        if (m_full) {
            // Если буфер уже заполнен, перемещаем конец буфера вперед, чтобы перезаписать самый старый элемент.
            m_tail = (m_tail + 1) % Capacity;
        }

        m_full = (m_head == m_tail);
    }

    /*
     * Метод извлечения элемента с конца буфера.
     * Возвращает std::nullopt, если буфер пуст.
     */
    std::optional<T> pop() {
        if (empty()) {
            return std::nullopt;
        }

        auto value = m_buffer[m_tail];
        m_full = false;
        m_tail = (m_tail + 1) % Capacity;

        return value;
    }

    /*
     * Метод для проверки буфера на пустоту
     */
    [[nodiscard]] bool empty() const {
        return !m_full && (m_head == m_tail);
    }

    /*
     * Метод для проверки буфера на полноту
     */
    [[nodiscard]] bool full() const {
        return m_full;
    }

    /*
     * Метод для получения максимального размера буфера
     */
    [[nodiscard]] std::size_t size() const {
        if (m_full) {
            return Capacity;
        }

        if (m_head >= m_tail) {
            return m_head - m_tail;
        }

        return Capacity + m_head - m_tail;
    }

    /*
     * Метод для получения текущей ёмкости буфера
     */
    [[nodiscard]] constexpr std::size_t capacity() const {
        return Capacity;
    }

private:
    std::array<T, Capacity> m_buffer{};  // Фиксированный массив для хранения
    std::size_t m_head{0};               // Индекс для записи
    std::size_t m_tail{0};               // Индекс для чтения
    bool m_full{false};                  // Флаг заполненности

};
