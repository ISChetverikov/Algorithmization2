#include <iostream>

#include "Stack.h"

int main() {
    const int SIZE = 10;
    auto stack = Stack<int>(SIZE);

    int i = 0;
    for (auto it = stack.begin(); it != stack.end(); it++)
    {
        *it = i;
        i++;
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << stack.Pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}