#pragma once

#include  <stdexcept>


class VectorBase
{
protected:
    int size;
    int _index = -1;

public:
    VectorBase(int sz) : size(sz) {}
    virtual ~VectorBase() {}

    int getSize() const {
        return size;
    }

    virtual void* at(int _index) = 0;

};

template<typename T>
class Vector : public VectorBase
{
private:
    T* buff;

public:
    Vector(int sz): VectorBase(sz) {
        buff = new T[sz];
    }

    ~Vector() {
        delete[] buff;
    }

    T& front() {
        if (_index == -1)
            throw std::out_of_range("out of range");
        else
            return buff[_index];
    }

    T& last() {
        return buff[_index - 1];
    }

    void insert(T t) {
        if (_index < size) {
            _index++;
            buff[_index] = t;
        }
    }

    T* at(int index) override {
        if (_index < index || index > size - 1)
            throw std::out_of_range("out of range");
        else {
            T* ptr = &buff[_index];
            return ptr;
        }
    }
};

