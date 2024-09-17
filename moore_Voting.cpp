#include <bits/stdc++.h>
using namespace std;

int moore_voting_algo(vector<int> &vec)
{

    // assuming the first element is the most occuring element
    int candidate = vec[0];
    int c = 1;
    int len = vec.size();

    // finding the candidate
    for (int i = 0; i < len; i++)
    {

        if (vec[i] == candidate)
        {
            c++;
        }
        else
        {
            c--;
            if (c == 0)
            {
                candidate = vec[i];
                c = 1;
            }
        }
    }

    // candidate verification
    int count = 0;
    for (auto &num : vec)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    if (count > len / 2)
    {
        return candidate;
    }
    return -1;
}

int main()
{
    vector<int> vec = {1, 1, 2, 3, 3, 3, 3};
    int val = moore_voting_algo(vec);
    cout << "Element occuring more the n/2 times in the array: " << val;
    return 0;
}