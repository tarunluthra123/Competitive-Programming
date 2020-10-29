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

#define ll long long
#define pii pair<ll, ll>
#define vi vector<ll>

#define inf (ll)1e18

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        ll a00 = a[0][0];
        ll ans = inf;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {

                ll need = a[x][y] - x - y;
                if (need > a00)
                    continue;
                a[0][0] = need;
                vector<vector<ll>> dp(n, vector<ll>(m, inf));
                dp[0][0] = a00 - need;

                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        ll need = a[0][0] + i + j;
                        if (need > a[i][j])
                            continue;
                        if (i > 0)
                            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - need);
                        if (j > 0)
                            dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - need);
                    }
                }
                ans = min(ans, dp[n - 1][m - 1]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
