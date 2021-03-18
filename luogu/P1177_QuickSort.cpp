#include <iostream>
#include <vector>
#include <climits>
void Insertion_Sort(std::vector<int> &arr, int start, int end)
{
    for (size_t i = start + 1; i < end + 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((j >= start) && (arr[j] > key))
        {
            // find correct position
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Merge(std::vector<int> &arr, int start, int mid, int end)
{
    // index of subarray
    int i = start;
    int j = mid + 1;
    std::vector<int> larr;
    std::vector<int> rarr;
    while (i < mid + 1)
    {
        larr.push_back(arr[i]);
        i++;
    }
    while (j < end + 1)
    {
        rarr.push_back(arr[j]);
        j++;
    }
    // avoid to check whether either piple is empty
    larr.push_back(INT_MAX);
    rarr.push_back(INT_MAX);
    // init
    i = j = 0;
    for (size_t k = start; k < end + 1; k++)
    {
        if (larr[i] < rarr[j])
        {
            arr[k] = larr[i];
            i++;
        }
        else
        {
            arr[k] = rarr[j];
            j++;
        }
    }
}
// improved merge sort
void Merge_Sort(std::vector<int> &arr, int start, int end)
{
    if ((end - start) <= 15)
    {
        Insertion_Sort(arr, start, end);
        return;
    }
    if (start < end)
    {
        int mid = (start + end) >> 1;
        Merge_Sort(arr, start, mid);
        Merge_Sort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}
int main()
{
    std::vector<int> arr;
    int size = 0;
    std::cin >> size;
    int num = 0;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> num;
        arr.push_back(num);
    }
    Merge_Sort(arr, 0, arr.size() - 1);
    for (auto &w : arr)
    {
        std::cout << w << " ";
    }
    return 0;
}