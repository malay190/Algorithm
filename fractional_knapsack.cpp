// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

// custom comparator based on value by weight
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractional_knapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compare);
    int current_cap = capacity;
    double profit = 0;
    for (auto item : items)
    {
        if (item.weight <= current_cap)
        {
            profit += item.value;
            current_cap -= item.weight;
        }
        else
        {
            profit += item.value * ((double)current_cap / item.weight);
            break;
        }
    }
    return profit;
}

int main()
{
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    double max_profit = fractional_knapsack(items, capacity);
    cout << max_profit;
    return 0;
}