#pragma once
#include <exception>

using namespace std;

class StackIsEmptyException : public exception {
public:
    const char * what() const throw ()
    {
        return "Stack is empty!";
    }
};

class StackIsFullException : public exception {
public:
    const char * what() const throw ()
    {
        return "Stack is full!";
    }
};

class QueueIsEmptyException : public exception {
public:
    const char * what() const throw ()
    {
        return "Stack is empty!";
    }
};

class QueueIsFullException : public exception {
public:
    const char * what() const throw ()
    {
        return "Stack is full!";
    }
};

