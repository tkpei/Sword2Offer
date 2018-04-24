#include <vector>
#include <queue>

#include "gtest/gtest.h"

#include "container/binary_tree.h"

using std::vector;

bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.size() <= 1)
        return true;

    vector<int> leftSequence;
    vector<int> rightSequence;
    int mid = sequence.back();
    int i;
    for (i = 0; i < sequence.size() - 1; i++)
    {
        if (sequence[i] < mid)
        {
            leftSequence.push_back(sequence[i]);
        }
        else
            break;
    }
    for (; i < sequence.size() - 1; i++)
    {
        if (sequence[i] > mid)
        {
            rightSequence.push_back(sequence[i]);
        }
        else
        {
            return false;
        }
    }
    if (VerifySquenceOfBST(leftSequence) && VerifySquenceOfBST(rightSequence))
    {
        return true;
    }
    return false;
}

TEST(VerifySquenceOfBSTTest, Normal)
{
    vector<int> sequence = { 5, 7, 6, 9, 11, 10, 8 };
    vector<int> sequence1 = { 7, 4, 6, 5 };

    EXPECT_EQ(VerifySquenceOfBST(sequence), true);
    EXPECT_EQ(VerifySquenceOfBST(sequence1), false);
}