#include "pch.h"
#include "../LW4/Stack.h"
#include "../LW4/Queue.h"

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

using testing::ElementsAreArray;
TEST(StackTest, BasicInterfaceTesting) {

    const int SIZE = 10;

    auto stack = Stack<int>(SIZE);

    int clearStackLength = stack.Length();
    bool clearStackIsEmpty = stack.isEmpty();

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
    int outputValuesArr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        stack.Push(inputValuesArr[i]);
    }

    int fullStackLength = stack.Length();
    bool fullStackIsEmpty = stack.isEmpty();

    for (int i = SIZE - 1; i >= 0; i--) {
        outputValuesArr[i] = stack.Pop();
    }

    int clearedStackLength = stack.Length();
    bool clearedStackIsEmpty = stack.isEmpty();

    EXPECT_EQ(clearStackLength, 0);
    EXPECT_TRUE(clearStackIsEmpty);
  
    EXPECT_EQ(fullStackLength, SIZE);
    EXPECT_FALSE(fullStackIsEmpty);

    EXPECT_EQ(clearedStackLength, 0);
    EXPECT_TRUE(clearedStackIsEmpty);

    ASSERT_THAT(outputValuesArr, ElementsAreArray(inputValuesArr));
}

TEST(StackTest, OutputIteratorTesting) {

    const int SIZE = 10;
    auto stack = Stack<int>(SIZE);

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
    int outputValuesArr[SIZE];

    int i = 0;
    for (auto it = stack.begin(); it != stack.end(); ++it)
    {
        *it = inputValuesArr[i];
        i++;
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        outputValuesArr[i] = stack.Pop();
    }

    ASSERT_THAT(outputValuesArr, ElementsAreArray(inputValuesArr));
}

TEST(QueueTest, BasicInterfaceTesting) {

    const int SIZE = 10;

    auto q = Queue<int>(SIZE);

    int clearQueueLength = q.Length();
    bool clearQueueIsEmpty = q.isEmpty();

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
    int outputValuesArr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        q.Enque(inputValuesArr[i]);
    }

    int fullQueueLength = q.Length();
    bool fullQueueIsEmpty = q.isEmpty();

    for (int i = 0; i < SIZE; i++) {
        outputValuesArr[i] = q.Dequeue();
    }

    int clearedQueueLength = q.Length();
    bool clearedQueueIsEmpty = q.isEmpty();

    EXPECT_EQ(clearQueueLength, 0);
    EXPECT_TRUE(clearQueueIsEmpty);

    EXPECT_EQ(fullQueueLength, SIZE);
    EXPECT_FALSE(fullQueueIsEmpty);

    EXPECT_EQ(clearedQueueLength, 0);
    EXPECT_TRUE(clearedQueueIsEmpty);

    ASSERT_THAT(outputValuesArr, ElementsAreArray(inputValuesArr));
}

TEST(QueueTest, ForwardIteratorTesting) {

    const int SIZE = 10;

    auto q = Queue<int>(SIZE);

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,0 };
    int outputValuesArr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        q.Enque(inputValuesArr[i]);
    }

    int i = 0;
    for (auto it = q.begin(); it != q.end(); ++it)
    {
        *it = *it * 2;
        i++;
    }

    for (auto it = q.begin(); it != q.end(); ++it);

    i = 0;
    for (auto it = q.begin(); it != q.end(); ++it)
    {
        outputValuesArr[i] = *(it.operator->());
        i++;
    }

    for (int i = 0; i < SIZE; i++)
    {
        inputValuesArr[i] *= 2;
    }

    ASSERT_THAT(outputValuesArr, ElementsAreArray(inputValuesArr));
}