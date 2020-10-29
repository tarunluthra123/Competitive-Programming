#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>>

vector<int> mergeKSortedArrays(vector<vector<int>> v)
{
    int k = v.size();
    int n = v[0].size();

    vector<int> res;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({v[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        ppi t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int rowNo = t.second.first;
        int colNo = t.second.second;
        if (colNo < n - 1)
        {
            pq.push({v[rowNo][colNo + 1], {rowNo, colNo + 1}});
        }
    }

    return res;
}

int main()
{
    int k;
    int n;
    cin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> res = mergeKSortedArrays(v);

    for (int i : res)
    {
        cout << i << " ";
    }

    return 0;
}
