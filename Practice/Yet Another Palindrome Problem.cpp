//https://codeforces.com/contest/1324/problem/B
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll long long int
#define pii pair<ll, ll>
#define vi vector<ll>

int main()
{
    sync;

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        map<int, vi> m;
        for (int i = 1; i <= n; i++)
        {
            m[v[i]].push_back(i);
        }

        string ans = "NO";

        for (auto x : m)
        {
            if (x.ss.size() >= 3)
            {
                ans = "YES";
                break;
            }
            if (x.ss.size() == 2 && x.ss[0] + 1 != x.ss[1])
            {
                ans = "YES";
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
