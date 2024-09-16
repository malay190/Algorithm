#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<float> &vec)
{

    int len = vec.size();
    for (int i = 1; i < len; i++)
    {
        float key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void bucket_sort(vector<float> &vec, int len)
{
    float max_value = *max_element(vec.begin(), vec.end());
    float min_value = *min_element(vec.begin(), vec.end());

    int num_bucket = 10;
    vector<vector<float>> buckets(num_bucket);

    // inserting the elements in the buckets
    for (auto num : vec)
    {

        // finding the index of the number in the buckets
        int num_index = static_cast<int>((num - min_value) * (num_bucket - 1) / (max_value - min_value));
        buckets[num_index].push_back(num);
    }

    // clearing the elements of the vector to store the sorted elements
    vec.clear();

    for (auto &bucket : buckets)
    {
        insertion_sort(bucket);
        vec.insert(vec.end(), bucket.begin(), bucket.end());
    }
}

int main()
{

    vector<float> vec = {0.35, 0.12, 0.43, 0.15, 0.04, 0.50, 0.132};
    int len = vec.size();
    bucket_sort(vec, len);
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}