#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    insertion_sort(arr, end);
    for (int i = 0; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}