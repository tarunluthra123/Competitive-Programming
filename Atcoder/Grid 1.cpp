#include <bits/stdc++.h>
using namespace std;

#define MOD (ll)(1e9+7)
#define ll long long 

int dp[1001][1001] = {0};
char grid[1001][1001];

int main() {
    int h,w;
    cin>>h>>w;
    for (int i = 0; i < h; ++i)
    {
        cin >> grid[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i < h; ++i)
    {
        if(grid[i][0] != '#')
            dp[i][0] = dp[i-1][0];
        else
            dp[i][0] = 0;
    }
    // cout << "ok1";
    for (int j = 1; j < w; ++j)
    {
        if(grid[0][j] != '#')
            dp[0][j] = dp[0][j-1];
        else
            dp[0][j] = 0;
    }

    // cout << "ok2";
    for (int i = 1; i < h; ++i)
    {
        for (int j = 1; j < w; ++j)
        {
            if(grid[i][j]=='#')
                dp[i][j] = 0;
            else {
                dp[i][j] = ((ll)dp[i-1][j] % MOD+ (ll)dp[i][j-1] % MOD) % MOD;
            }
        }
    }

    // for (int i = 0; i < h; ++i)
    // {
    //     for (int j = 0; j < w; ++j)
    //     {
    //         cout << dp[i][j]  << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[h-1][w-1] % MOD << "\n";

    return 0;
}