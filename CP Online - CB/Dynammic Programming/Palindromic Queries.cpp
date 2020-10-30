#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

int main() {
    sync;
    int n;
    cin >> n;
    string s;
    cin >> s;


    vector<vector<bool>>dp(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j + i - 1 < n; j++) {
            int start = j, end = j + i - 1;
            if (i == 2) {
                dp[start][end] = (s[start] == s[end]);
            }
            else {
                dp[start][end] = (s[start] == s[end]) && dp[start + 1][end - 1];
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    int testCases;
    cin >> testCases;
    while (testCases--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << (dp[l][r] ? "YES\n" : "NO\n");
    }

    return 0;
}
