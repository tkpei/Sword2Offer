#include <vector>
#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

using std::vector;

int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0)
        return 0;

    int left = 0, right = static_cast<int>(rotateArray.size()) - 1;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (rotateArray[mid] < rotateArray[right])
            right = mid;
        else if(rotateArray[mid] > rotateArray[right])
            left = mid + 1;
        else
        {
            int minNumber = rotateArray[left];
            for (int i = left; i <= right; i++)
            {
                if (rotateArray[i] < minNumber)
                    minNumber = rotateArray[i];
            }
            return minNumber;
        }
    }
    return std::min(rotateArray[left], rotateArray[right]);
}

TEST(MinNumberInRotateArrayTest, Normal)
{
    vector<int> array = { 3, 4, 5, 1, 2 };
    EXPECT_EQ(minNumberInRotateArray(array), 1);
}
