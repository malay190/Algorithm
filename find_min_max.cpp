#include <bits/stdc++.h>
using namespace std;

vector<int> dac_find_min_max(vector<int> &vec, int start, int end)
{

    int max = INT_MIN;
    int min = INT_MAX;

    if (start == end)
    {
        min = vec[start];
        max = vec[start];
        return {max, min};
    }
    else if (start == end - 1)
    {
        if (vec[start] > vec[end])
        {
            min = vec[end];
            max = vec[start];
        }
        else
        {
            min = vec[start];
            max = vec[end];
        }
        return {max, min};
    }
    else
    {
        int mid = floor((start + end) / 2);
        vector<int> left_result = dac_find_min_max(vec, start, mid);
        vector<int> right_result = dac_find_min_max(vec, mid + 1, end);

        int max1 = left_result[0];
        int min1 = left_result[1];
        int max2 = right_result[0];
        int min2 = right_result[1];

        max = max1 >= max2 ? max1 : max2;
        min = min1 <= min2 ? min1 : min2;
        return {max, min};
    }
}

int main()
{

    vector<int> vec = {9, 6, 0, 5, 0, 8, 2, 4, 7};
    vector<int> new_vec;
    int start = 0;
    int end = vec.size() - 1;
    new_vec = dac_find_min_max(vec, start, end);
    for (auto num : new_vec)
    {
        cout << num << endl;
    }
    return 0;
}