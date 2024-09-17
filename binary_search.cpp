#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &vec, int i, int j, int target)
{
    while (i <= j)
    {
        int mid = floor((i + j) / 2);
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {0, 0, 2, 3, 6, 7, 8, 9};
    int x = 6;
    int start = 0;
    int end = vec.size() - 1;
    int val = binary_search(vec, start, end, x);
    cout << val;
    return 0;
}