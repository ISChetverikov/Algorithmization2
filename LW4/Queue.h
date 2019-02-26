#pragma once
#include <iterator>
#include <exception>
#include "Exception.h"

//using namespace std;

template <class T>
class Queue {

private:
    T* _pointer;
    int _length;
    int _capacity;

public:

    class forward_iterator {

    private:
        int _index = 0;
        Queue* _queueObjectPointer;

        typedef forward_iterator self_type;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T * ;
        using reference = T & ;

        forward_iterator(Queue* queueObjectPointer, int index) {

            if (index > queueObjectPointer->_length)
                throw std::out_of_range("Queue's ouptut iterator is out of range in constuctor");

            _index = index;
            _queueObjectPointer = queueObjectPointer;
        }

        self_type operator++(int junk) {
            self_type tmp = *this;
            _index++;

            if (_index > _queueObjectPointer->_length)
                throw std::out_of_range("Queue's ouptut iterator is out of range in constuctor");

            return tmp;
        }

        self_type operator++() {
            _index++;

            if (_index > _queueObjectPointer->_length)
                throw std::out_of_range("Stack's ouptut iterator is out of range in constuctor");

            return *this;
        }

        reference operator*() {
            return *(_queueObjectPointer->_pointer + _index);
        }

        pointer operator->() {
            return _queueObjectPointer->_pointer + _index;
        }

        bool operator==(const self_type& rhs) const {
            return _queueObjectPointer == rhs._queueObjectPointer && _index == rhs._index;
        }

        bool operator!=(const self_type& rhs) {
            return !(*this == rhs);
        }

    };

public:
    Queue(int capacity) {
        _capacity = capacity;
        _pointer = new T[_capacity];

        _length = 0;
    }

    bool isEmpty() {
        return _length == 0;
    }

    int Length() {
        return _length;
    }

    void Enque(T element) {
        
        if (_length >= _capacity)
            throw QueueIsFullException();

        _pointer[_length] = element;
        _length++;
    }

    T Dequeue() {

        if (_length <= 0)
            throw QueueIsEmptyException();

        T res = _pointer[0];
        _length--;

        if (_length > 0)
            std::copy(_pointer + 1, _pointer + _length + 1, _pointer);

        return res;
    }

    ~Queue() {
        delete[] _pointer;
    }

    forward_iterator begin() {
        return forward_iterator(this, 0);
    }

    forward_iterator end() {
        return forward_iterator(this, _length);
    }

};