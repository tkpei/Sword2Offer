#include <vector>

#include "gtest/gtest.h"

class Solution
{
public:
    Solution(): firstCharIndex(-1)
    {
        memset(hashTable, 0, 256 * sizeof(char));
    }

    //Insert one char from stringstream
    void Insert(char ch)
    {
        if (firstCharIndex == -1)
        {
            firstCharIndex = static_cast<int>(data.size());
        }
        else if (data[firstCharIndex] == ch)
        {
            int i;
            for (i = firstCharIndex + 1; i < data.size(); i++)
            {
                if (hashTable[data[i]] <= 1)
                {
                    firstCharIndex = i;
                    break;
                }
            }
            if (i >= data.size())
            {
                firstCharIndex = -1;
            }
        }

        data.push_back(ch);
        hashTable[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if (firstCharIndex == -1)
            return '#';
        return data[firstCharIndex];
    }

    unsigned char hashTable[255];
    int firstCharIndex;
    std::vector<char> data;
};