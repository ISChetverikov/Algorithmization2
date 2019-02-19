#pragma once
#include <iterator>

template <class T>
class Stack {
    T* pointer;
    int index;
    int capacity;
    const int INIT_CAPACITY = 10;

    void Resize() {
        int newCapacity = capacity * 2;
        T* newPointer = new T[newCapacity];

        std::copy(pointer, pointer+capacity, newPointer);

        delete[] pointer;
        capacity = newCapacity;
        pointer = newPointer;
    }

public:
    Stack() {
        capacity = INIT_CAPACITY;
        pointer = new T[capacity];

        index = -1;
    }

    bool isEmpty() {
        return index == -1;
    }

    int Length() {
        return index + 1;
    }

    void Push(T element) {
        index++;

        if (index >= capacity)
            Resize();

        pointer[index] = element;
        
    }

    T Pop() {
        T res = pointer[index];
        index--;
        
        return res;
    }

    ~Stack() {
        delete[] pointer;
    }

    class OutpuIterator {
    public:
        typedef OutpuIterator self_type;

        using iterator_category = std::output_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        self_type operator++() {
            self_type tmp = *this; 
            _ptr++;
            return tmp;
        }
        self_type operator++(int junk) { 
            _ptr++; 
            return *this;
        }
        const reference operator*() { return *ptr_; }

    private:
        pointer _ptr;
    };
};