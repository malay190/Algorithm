#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{

    auto compare = [](pair<int, double> a, pair<int, double> b)
    {
        return a.second < b.second;
    };

    vector<pair<int, double>> vec;

    for (int i = 0; i < points.size(); i++)
    {
        double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        vec.push_back({i, dis});
    }

    sort(vec.begin(), vec.end(), compare);

    vector<vector<int>> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(points[vec[i].first]);
    }

    return ans;
}

int main()
{

    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    vector<vector<int>> result = sol.kClosest(points, k);

    cout << "The " << k << " closest points are:\n";
    for (const auto &point : result)
    {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}