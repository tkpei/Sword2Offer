#include <vector>
#include <stack>
#include <exception>

#include "gtest/gtest.h"

namespace
{
    const double limitation = 0.000001;

    bool equal(double num1, double num2)
    {
        if (std::abs(num1 - num2) < limitation)
            return true;
        return false;
    }

}

double power(double base, int exponent) {
    if (equal(base, 0.0) && exponent < 0)
    {
        throw std::exception("power function: input base < 0 && exponent < 0");
        return 0.0;
    }

    double result = 1.0;
    for (int i = 0; i < std::abs(exponent); i++)
    {
        result *= base;
    }
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}

