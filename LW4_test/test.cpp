#include "pch.h"
#include "../LW4/Stack.h"

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

using testing::ElementsAreArray;
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
