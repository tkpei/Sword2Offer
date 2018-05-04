#include <vector>

#include "gtest/gtest.h"

#include "algorithm/sort.h"

TEST(QuickSortTest, Normal)
{
    std::vector<int> data = { 6, 4, 2, 1, 3, 5 };
    std::vector<int> dataExpect = { 1, 2, 3, 4, 5, 6 };
    quickSort(data);

    EXPECT_EQ(data, dataExpect);
}

TEST(SimpleSelectionSortTest, Normal)
{
    std::vector<int> data = { 6, 4, 2, 1, 3, 5 };
    std::vector<int> dataExpect = { 1, 2, 3, 4, 5, 6 };
    simpleSelectionSort(data);

    EXPECT_EQ(data, dataExpect);
}


TEST(InsertionSortTest, Normal)
{
    std::vector<int> data = { 6, 4, 2, 1, 3, 5 };
    std::vector<int> dataExpect = { 1, 2, 3, 4, 5, 6 };
    insertionSort(data);

    EXPECT_EQ(data, dataExpect);
}

TEST(BubbleSortTest, Normal)
{
    std::vector<int> data = { 6, 4, 2, 1, 3, 5 };
    std::vector<int> dataExpect = { 1, 2, 3, 4, 5, 6 };
    bubbleSort(data);

    EXPECT_EQ(data, dataExpect);
}