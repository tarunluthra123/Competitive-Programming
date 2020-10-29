#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int[3]> dp(n+1);

    for (int i = 0; i < 3; ++i)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = max(dp[i-1][1]+b[i-1], dp[i-1][2]+c[i-1]);
        dp[i][1] = max(dp[i-1][0]+a[i-1], dp[i-1][2]+c[i-1]);
        dp[i][2] = max(dp[i-1][0]+a[i-1], dp[i-1][1]+b[i-1]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";

    return 0;
}   