#include <vector>

#include "gtest/gtest.h"

using std::vector;

vector<int> PrintMatrix(vector<vector<int> > matrix) {
    size_t height = matrix.size();
    size_t width = matrix[0].size();
    vector<int> result;
    if (height == 0 || width == 0)
    {
        return result;
    }

    int topEnd = 1, bottomEnd = (int)height - 1;
    int leftEnd = 0, rightEnd = (int)width - 1;
    int x = 0, y = 0, count = 0;
    while (1)   //fix
    {
        for (; x <= rightEnd; x++, count++)
            result.push_back(matrix[y][x]);
        rightEnd--;
        x--;
        y++;
        if (count >= height * width)
            break;
        for (; y <= bottomEnd; y++, count++)
            result.push_back(matrix[y][x]);
        bottomEnd--;
        y--;
        x--;
        if (count >= height * width)
            break;
        for (; x >= leftEnd; x--, count++)
            result.push_back(matrix[y][x]);
        leftEnd++;
        x++;
        y--;
        if (count >= height * width)
            break;
        for(; y>= topEnd;y--, count++)
            result.push_back(matrix[y][x]);
        topEnd++;
        y++;
        x++;
        if (count >= height * width)
            break;
    }
    return result;
}

TEST(PrintMatrixTest, PrintMatrix1row)
{
    vector<vector<int>> input = { { 1, 2, 3, 4 }};
    vector<int> output;
    vector<int> outputExcept = { 1, 2, 3, 4};
    output = PrintMatrix(input);

    EXPECT_EQ(output.size(), outputExcept.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], outputExcept[i]);
    }
}

TEST(PrintMatrixTest, PrintMatrix1col)
{
    vector<vector<int>> input = { { 1}, {2 }, {3}, {4}};
    vector<int> output;
    vector<int> outputExcept = { 1, 2, 3, 4 };
    output = PrintMatrix(input);

    EXPECT_EQ(output.size(), outputExcept.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], outputExcept[i]);
    }
}

TEST(PrintMatrixTest, PrintMatrix2row)
{
    vector<vector<int>> input = { {1, 2, 3, 4},{5, 6, 7, 8} };
    vector<int> output;
    vector<int> outputExcept = { 1, 2, 3, 4, 8, 7, 6, 5 };
    output = PrintMatrix(input);

    EXPECT_EQ(output.size(), outputExcept.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], outputExcept[i]);
    }
}

TEST(PrintMatrixTest, PrintMatrix4row)
{
    vector<vector<int>> input = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 },
                                  { 11, 12, 13, 14, 15}, {16, 17, 18, 19, 20} };
    vector<int> output;
    vector<int> outputExcept = { 1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17,
                                 16, 11, 6, 7, 8, 9, 14, 13, 12};
    output = PrintMatrix(input);

    EXPECT_EQ(output.size(), outputExcept.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], outputExcept[i]);
    }
}