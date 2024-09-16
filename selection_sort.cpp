#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }
}

int main()
{

    int arr[] = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    int end = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, end);
    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}