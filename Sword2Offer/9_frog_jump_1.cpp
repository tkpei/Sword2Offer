#include "gtest/gtest.h"

int jumpFloorII(int number) {
    if (number <= 0)
        return 0;
    return pow(2, number - 1);
}