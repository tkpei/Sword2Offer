#include <vector>
#include <stack>

#include "gtest/gtest.h"

using std::stack;

class MinStack
{
public:
    void push(int value)
    {
        data.push(value);
        if (minNumber.size() == 0 || value < minNumber.top())
            minNumber.push(value);
        else minNumber.push(minNumber.top());
    }
    void pop()
    {
        data.pop();
        minNumber.pop();
    }
    int top()
    {
        return data.top();
    }
    int min()
    {
        return minNumber.top();
    }
private:
    stack<int> data;
    stack<int> minNumber;
};