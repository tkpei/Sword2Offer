#include "gtest/gtest.h"

int rectCover(int number) {
    if (number <= 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (number == 2)
    {
        return 2;
    }

    int pre1, pre2;
    pre1 = 2;
    pre2 = 1;
    int result;
    for (int i = 3; i <= number; i++)
    {
        result = pre1 + pre2;
        pre2 = pre1;
        pre1 = result;
    }

    return result;
}