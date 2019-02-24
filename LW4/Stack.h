#pragma once
#include <iterator>
#include <exception>
#include "Exception.h"

//using namespace std;

template <class T>
class Stack {

private:
    T* _pointer;
    int _index;
    int _capacity;
    
    T* Peak() {
        if (isEmpty())
            throw StackIsEmptyException();

        return _pointer + _index;
    }

    T* PushDummy() {
        Push((T)0);

        return Peak();
    }
    

public:
    class output_iterator {

    private:
        int _index = 0;
        Stack* _stackObjectPointer;

    public:
        typedef output_iterator self_type;

        using iterator_category = std::output_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        output_iterator(Stack* stackObjectPointer, int index) {

            if (index > stackObjectPointer->_capacity)
                throw std::out_of_range("Stack's ouptut iterator is out of range in constuctor");

            _index = index;
            _stackObjectPointer = stackObjectPointer;
        }

        self_type operator++(int junk) {
            self_type tmp = *this;
            _index++;

            if (_index > _stackObjectPointer->_capacity)
                throw std::out_of_range("Stack's ouptut iterator is out of range in constuctor");

            return tmp;
        }

        self_type operator++() {
            _index++;

            if (_index > _stackObjectPointer->_capacity)
                throw std::out_of_range("Stack's ouptut iterator is out of range in constuctor");

            return *this;
        }

        const reference operator*() {
            return *_stackObjectPointer->PushDummy();
        }

        bool operator==(const self_type& rhs) const {
            return _stackObjectPointer == rhs._stackObjectPointer && _index == rhs._index;
        }

        bool operator!=(const self_type& rhs) { 
            return !(*this==rhs); 
        }

    };

    Stack(int capacity) {
        _capacity = capacity;
        _pointer = new T[_capacity];

        _index = -1;
    }

    bool isEmpty() {
        return _index == -1;
    }

    int Length() {
        return _index + 1;
    }

    void Push(T element) {
        _index++;

        if (_index >= _capacity)
            throw StackIsFullException();

        _pointer[_index] = element;
    }

    T Pop() {
        T res = _pointer[_index];
        _index--;
        
        return res;
    }

    ~Stack() {
        delete[] _pointer;
    }

    output_iterator begin() {
        return output_iterator(this, 0);
    }

    output_iterator end() {
        return output_iterator(this, _capacity);
    }

    
};