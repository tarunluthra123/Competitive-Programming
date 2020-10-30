#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli dp[1000][1000];
lli a[1000];
lli n;


lli sum(int s, int e) {
    lli ans = 0 ;
    for (int i = s; i <= e; i++) {
        ans += a[i];
        ans %= 100;
    }
    return ans ;
}


lli mixtures(int i, int j) {
    //Base case
    if (i >= j) {
        return 0;
    }

    //If answer is already there
    if (dp[i][j] != -1) {
        return dp[i][j] ;
    }

    //Break expression at every k
    dp[i][j] = INT_MAX ;
    for (int k = i; k <= j; k++) {
        lli smokeNow = sum(i, k) * sum(k + 1, j);
        dp[i][j] = min(dp[i][j], mixtures(i, k) + mixtures(k + 1, j) + smokeNow) ;
    }

    return dp[i][j];
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        cout << mixtures(0, n - 1) << "\n";
    }

    return 0;
}

