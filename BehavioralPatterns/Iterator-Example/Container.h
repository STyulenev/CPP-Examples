#pragma once

#include <vector>

template <typename T, typename U>
class Iterator;

/*!
 * \brief Класс-контейнер, который может взаимодействовать с итератором
 */
template <class T>
class Container
{
    friend class Iterator<T, Container>;

public:
    void add(T a) {
        m_data_.push_back(a);
    }

    Iterator<T, Container>* createIterator() {
        return new Iterator<T, Container>(this);
    }

private:
    std::vector<T> m_data_;

};
