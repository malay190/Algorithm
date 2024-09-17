#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int i)
{
    int n = heap.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check the left child exist and is it largest than the parent
    if (left < n && heap[left] > heap[i])
    {
        largest = left;
    }

    // check the right child exist and is it largest than the parent
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void build_heap(vector<int> &heap)
{
    int n = heap.size();
    int start_index = (n / 2) - 1;
    for (int i = start_index; i >= 0; i--)
    {
        heapify(heap, i);
    }
}

int main()
{
    vector<int> heap = {9, 6, 0, 5, 0, 8, 2, 4, 7}; // Input array

    cout << "Original Array: ";
    for (int i : heap)
        cout << i << " ";
    cout << endl;

    // Build a max-heap
    build_heap(heap);

    // Print the heap after building it
    cout << "Max-Heap: ";
    for (int i : heap)
        cout << i << " ";
    cout << endl;

    return 0;
}