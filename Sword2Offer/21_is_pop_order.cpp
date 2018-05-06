#include <stack>
#include <vector>

#include "gtest/gtest.h"

using std::stack;
using std::vector;

bool isPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.size() != popV.size())
        return false;
    if (pushV.size() == 0)
        return true;

    stack<int> dataSequence;
    int popVIndex = 0;

    for (int i = 0; i < pushV.size(); i++)
    {
        if (pushV[i] == popV[popVIndex])
        {
            popVIndex++;
            while (dataSequence.size() > 0 && dataSequence.top() == popV[popVIndex])
            {
                popVIndex++;
                dataSequence.pop();
            }
        }
        else
        {
            dataSequence.push(pushV[i]);
        }
    }
    while (dataSequence.size() > 0 && dataSequence.top() == popV[popVIndex])
    {
        popVIndex++;
        dataSequence.pop();
    }
    return dataSequence.size() == 0;
}


TEST(IsPopOrderTest, Normal)
{
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    vector<int> popV1 = { 4,5,3,1,2 };
    EXPECT_TRUE(isPopOrder(pushV, popV));
    EXPECT_FALSE(isPopOrder(pushV, popV1));
}