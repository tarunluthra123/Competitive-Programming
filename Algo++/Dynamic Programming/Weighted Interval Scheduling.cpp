#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ss second
#define ff first

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<pair<int, pii>> jobs(n);
    for (int i = 0; i < n; ++i)
    {
        jobs[i] = {endTime[i], {startTime[i], profit[i]}};
    }
    sort(jobs.begin(), jobs.end());
    map<int, int> dp = {{0, 0}};
    for (auto &job : jobs)
    {
        int cur = prev(dp.upper_bound(job.ss.ff))->ss + job.ss.ss;
        if (cur > dp.rbegin()->ss)
            dp[job.ff] = cur;
    }
    return dp.rbegin()->ss;
}
int main()
{
    int n;
    cin >> n;

    vector<int> startTime(n), endTime(n), profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> startTime[i] >> endTime[i] >> profit[i];
    }

    cout << jobScheduling(startTime, endTime, profit);

    return 0;
}
