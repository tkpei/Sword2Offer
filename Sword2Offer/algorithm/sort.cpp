#include "sort.h"

namespace
{
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(std::vector<int>& data, int left, int right)
    {
        int pivot = data[left];
        int i = left;
        int j = right;
        while (1)
        {
            while (data[i] < pivot) i++;
            while (data[j] > pivot) j--;
            if (i >= j)
                break;
            else swap(data[i], data[j]);;
        }
        return j;
    }

    void qSort(std::vector<int>& data, int left, int right)
    {
        if (left >= right)
        return;

        int p = partition(data, left, right);
        qSort(data, left, p);
        qSort(data, p + 1, right);
    }
}

void quickSort(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    qSort(data, 0, static_cast<int>(data.size() - 1));
}
