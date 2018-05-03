#include <vector>

#include "gtest/gtest.h"

#include "algorithm/search.h"

TEST(BinarySearchTest, Normal)
{
    std::vector<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    EXPECT_EQ(binarySearch(data, -1), -1);
    EXPECT_EQ(binarySearch(data, 0), 0);
    EXPECT_EQ(binarySearch(data, 4), 4);
    EXPECT_EQ(binarySearch(data, 7), 7);
    EXPECT_EQ(binarySearch(data, 9), -1);
}