#include <bits/stdc++.h>
using namespace std;

// Important part of the quick sort is the partition algorithm, it will put the pivot element in the
// right position in the array such that the element to the left of the pivot is smaller and the element to the
// right side of the array is greater.
int partition(int arr[], int first, int last)
{
    int x = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++)
    {
        if (x >= arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}
void quick_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int q = partition(arr, first, last);
        quick_sort(arr, first, q - 1);
        quick_sort(arr, q + 1, last);
    }
}
int main()
{

    int arr[] = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    quick_sort(arr, start, end);
    for (int i = 0; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}