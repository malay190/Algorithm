// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int start, int end)
{
    int pivot = vec[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[end]);
    return i + 1;
}

int kth_smallest(vector<int> &vec, int start, int end, int k)
{

    int first = start;
    int last = end;

    if (first == last)
        return vec[first];
    else
    {
        int m = partition(vec, first, last);
        if (m == k - 1)
        {
            return vec[m];
        }
        else if (m > k - 1)
        {
            return kth_smallest(vec, first, m - 1, k);
        }
        else
        {
            return kth_smallest(vec, m + 1, last, k);
        }
    }
}

int main()
{

    vector<int> vec = {7, 5, 3, 6, 1, 0, 4, 8, 9};
    int len = vec.size() - 1;
    int k = 4;
    cout << kth_smallest(vec, 0, len, k);

    return 0;
}