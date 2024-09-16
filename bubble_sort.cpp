#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int len)
{
    int swapped = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{

    int arr[] = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    int end = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, end);
    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}