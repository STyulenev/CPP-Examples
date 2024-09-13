#pragma once

#include <vector>

/*!
 * \brief Итератор позволяет последовательно обходить элементы составных объектов, не раскрывая их внутреннего представления.
 */
template <typename DataType, typename ContainerType>
class Iterator
{
public:
    typedef typename std::vector<DataType>::iterator iterType;

    Iterator(ContainerType* p_data, bool reverse = false) : m_p_data_(p_data) {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void first() {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void next() {
        m_it_++;
    }

    bool isDone() {
        return (m_it_ == m_p_data_->m_data_.end());
    }

    iterType current() {
        return m_it_;
    }

private:
    ContainerType* m_p_data_;
    iterType       m_it_;

};
