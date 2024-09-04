#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < a.size(); i++)
    {
        max_ending_here = max_ending_here + a[i];
        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

int main()
{
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Maximum contiguous sum is "
         << maxSubArraySum(a);
    return 0;
}