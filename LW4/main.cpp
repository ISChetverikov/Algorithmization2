#include <iostream>
#include <queue>
#include <algorithm>
#include "Stack.h"
#include "Queue.h"

int main() {
    const int SIZE = 10;

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
    auto q = Queue<int>(SIZE);
    for (int i = 0; i < SIZE; i++) {
        q.Enque(inputValuesArr[i]);
    }

    int i = 0;
    for (auto it = q.begin(); it != q.end(); ++it)
    {
        *it = inputValuesArr[i] * 2;
        i++;
    }

    for (auto it = q.begin(); it != q.end(); ++it)
    {
        std::cout << *it;
    }

    std::cout << std::endl;
    for (auto it = q.begin(); it != q.end(); ++it)
    {
        std::cout << *(it.operator->()) << std::endl;
    }


    return 0;
}