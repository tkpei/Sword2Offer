#include "search.h"

int binarySearch(std::vector<int>& data, int element)
{
    if (data.size() <= 0)
        return -1;

    int low = 0, high = static_cast<int>(data.size()) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == element)
            return mid;
        else if (data[mid] < element)
            low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
