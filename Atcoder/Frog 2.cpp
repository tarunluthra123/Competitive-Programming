#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }


    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = INT_MAX;
        for(int j=i-1;j>=0 && i-j<=k;j--) {
            dp[i] = min(dp[j] + abs(v[i]-v[j]), dp[i]);
        }
    }

    cout << dp[n-1] << "\n";

    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i] << " " ;
    // }

    return 0;
}