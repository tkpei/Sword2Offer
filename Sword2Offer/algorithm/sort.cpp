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

void simpleSelectionSort(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    for (int i = 0; i < data.size() - 1; i++)   /* 遍历到倒数第二个 */
    {
        int minIndex = i;
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        swap(data[i], data[minIndex]);
    }
    return;
}

void insertionSort(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    for (int i = 1; i < data.size(); i++)
    {
        int j;
        int temp = data[i];
        for (j = i; j > 0 && data[j - 1] > temp; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = temp;
    }
}

void bubbleSort(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    for (int i = static_cast<int>(data.size()) - 1; i > 0; i--)
    {
        int flag = false;
        for (int j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                flag = true;
            }
        }
        if (flag == false) break;
    }
}