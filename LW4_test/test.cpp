#include "pch.h"
#include "../LW4/Stack.h"

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING


using testing::ElementsAreArray;
TEST(StackTest, BasicInterfaceTesting) {
    auto stack = Stack<int>();
    const int SIZE = 10;
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

TEST(StackTest, ResizingStackTesting) {
    auto stack = Stack<int>();
    const int SIZE = 20;

    int inputValuesArr[SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int outputValuesArr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        stack.Push(inputValuesArr[i]);
    }

    int fullStackLength = stack.Length();
    bool fullStackIsEmpty = stack.isEmpty();

    for (int i = SIZE - 1; i >= 0; i--) {
        outputValuesArr[i] = stack.Pop();
    }

    EXPECT_EQ(fullStackLength, SIZE);
    EXPECT_FALSE(fullStackIsEmpty);

    ASSERT_THAT(outputValuesArr, ElementsAreArray(inputValuesArr));
}