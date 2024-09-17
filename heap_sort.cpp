#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int len, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && heap[left] > heap[i])
        largest = left;

    if (right < len && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        heapify(heap, len, largest);
    }
}

void heap_sort(vector<int> &heap)
{
    int n = heap.size();

    int start_index = (n / 2) - 1;

    // build max heap
    for (int i = start_index; i >= 0; i--)
    {
        heapify(heap, n, i);
    }

    // start sorting
    for (int i = n - 1; i >= 1; i--)
    {
        swap(heap[i], heap[0]);
        heapify(heap, i, 0);
    }
}

int main()
{
    vector<int> heap = {9, 6, 0, 5, 0, 8, 2, 4, 7}; // Input array

    heap_sort(heap);
    for (int i : heap)
        cout << i << " ";

    return 0;
}