#include "gtest/gtest.h"

void ReplaceSpace(char *str, int length) {
    if (str == NULL || length <= 0)
        return;

    int outputLength = length;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            outputLength += 2;
        }
    }

    for (int i = length - 1, j = outputLength - 1; i >= 0; i--, j--)
    {
        if (str[i] == ' ')
        {
            str[j] = '0';
            str[j - 1] = '2';
            str[j - 2] = '%';
            j -= 2;
        }
        else
        {
            str[j] = str[i];
        }
    }
}

TEST(ReplaceSpaceTest, ReplaceSpace)
{
    char str[20] = "We Are Happy";
    ReplaceSpace(str, 12);
    char strExpect[20] = "We%20Are%20Happy";

    ASSERT_STREQ(strExpect, str);
}

TEST(ReplaceSpaceTest, nullInput)
{
    char str[20] = "";
    ReplaceSpace(str, 0);
    char strExpect[20] = "";

    ASSERT_STREQ(strExpect, str);
}

TEST(ReplaceSpaceTest, ContinueSpace)
{
    char str[20] = "   i   ";
    ReplaceSpace(str, 7);
    char strExpect[20] = "%20%20%20i%20%20%20";

    ASSERT_STREQ(strExpect, str);
}