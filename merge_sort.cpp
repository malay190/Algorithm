#include <bits/stdc++.h>
using namespace std;

// Important part in the merge sort is the merge algorithm, that will merge the two array and merge sort is a
// outplace algorithm
void merge(int arr[], int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[first + i];
    }
    arr1[n1] = INT_MAX;

    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }
    arr2[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = first; k <= last; k++)
    {
        if (arr1[i] > arr2[j])
        {
            arr[k] = arr2[j];
            j++;
        }
        else
        {
            arr[k] = arr1[i];
            i++;
        }
    }
    delete[] arr1;
    delete[] arr2;
}

void merge_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int q = floor((first + last) / 2);
        merge_sort(arr, first, q);
        merge_sort(arr, q + 1, last);
        merge(arr, first, q, last);
    }
}
int main()
{

    int arr[] = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    merge_sort(arr, start, end);
    for (int i = 0; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}