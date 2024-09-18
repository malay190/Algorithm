#include <bits/stdc++.h>
using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void job_sequencing(vector<Job> &jobs)
{
    // sort the jobs based on the profit
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto job : jobs)
    {
        if (maxDeadline < job.deadline)
        {
            maxDeadline = job.deadline;
        }
    }

    // array to keep track of jobs
    vector<int> result(maxDeadline, -1);

    // array to keep track of slot
    vector<bool> slot(maxDeadline, false);

    int profit = 0;

    // iterate through all the jobs
    for (int i = 0; i < jobs.size(); i++)
    {

        // finding the slot for the job
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Selected Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i])
        {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << "\nTotal Profit: " << profit << endl;
}

int main()
{
    vector<Job> jobs = {{"J1", 2, 100}, {"J2", 1, 19}, {"J3", 2, 27}, {"J4", 1, 25}, {"J5", 3, 15}};
    job_sequencing(jobs);
    return 0;
}