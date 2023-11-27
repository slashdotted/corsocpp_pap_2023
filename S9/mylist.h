#pragma once
#include <stdexcept>
#include <iostream>

// template <class X>
template <typename X>
class MyList {
public:
    explicit MyList(unsigned int size);
    MyList(const MyList& o) = delete;
    MyList(const MyList&& o) = delete;
    X& operator=(const MyList& o) = delete;
    X& operator=(const MyList&& o) = delete;
    ~MyList();
    X& operator[](unsigned int i);
    const X& operator[](unsigned int i) const;
    int size() const;
private:
    X* m_array;
    unsigned int m_size;
};

template <typename X>
MyList<X>::MyList(unsigned int size)
{
    if (size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    m_array = new X[size];
    m_size = size;
}

template <typename X>
const X& MyList<X>::operator[](unsigned int i) const
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template <typename X>
X& MyList<X>::operator[](unsigned int i)
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template <typename X>
int MyList<X>::size() const
{
    return m_size;
}

template <typename X>
MyList<X>::~MyList() {
    delete[] m_array;
}

