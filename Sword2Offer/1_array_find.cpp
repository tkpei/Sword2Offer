#include <vector>
#include <iostream>

#include "gtest/gtest.h"

using std::vector;

bool Find(int target, vector<vector<int> > array) {
    if (array.size() == 0 || array[0].size() == 0)
    {
        return false;
    }

    size_t height = array.size();
    size_t width = array[0].size();
    int x, y;

    x = static_cast<int>(width - 1);
    y = 0;
    while (x >= 0 && y < height)
    {
        int temp = array[y][x];
        if (target > temp)
        {
            y++;
        }
        else if(target < temp)
        {
            x--;
        }
        else if (target == temp)
        {
            return true;
        }
    }
    return false;
}

TEST(ArrayFindTest, ArrayFind) {
    vector<vector<int> > array = { {1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15} };
    EXPECT_FALSE(Find(50, array));
    EXPECT_FALSE(Find(5, array));
    EXPECT_FALSE(Find(-1, array));
    EXPECT_FALSE(Find(3, array));
    EXPECT_TRUE(Find(11, array));
    EXPECT_TRUE(Find(15, array));
    EXPECT_TRUE(Find(6, array));
    EXPECT_TRUE(Find(2, array));
}

TEST(ArrayFindTest, ArrayFindOneRow) {
    vector<vector<int> > array = { { 1, 2, 8, 9 } };
    EXPECT_FALSE(Find(-1, array));
    EXPECT_FALSE(Find(15, array));
    EXPECT_FALSE(Find(6, array));
    EXPECT_TRUE(Find(2, array));
}

TEST(ArrayFindTest, ArrayFindOneCol) {
    vector<vector<int> > array = { { 1}, {2}, {8}, {9} };
    EXPECT_FALSE(Find(-1, array));
    EXPECT_FALSE(Find(15, array));
    EXPECT_FALSE(Find(6, array));
    EXPECT_TRUE(Find(2, array));
}