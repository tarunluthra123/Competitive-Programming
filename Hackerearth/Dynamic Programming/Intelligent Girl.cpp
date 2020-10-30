//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/intelligent-girl-1/description/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n);
    dp[n - 1] = (s[n - 1] - '0') % 2 == 0;
    for (int i = n - 2; i >= 0; i--) {
        int r = s[i] - '0';
        dp[i] = dp[i + 1] + (r % 2 == 0);
    }

    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " " ;
    }

    return 0;
}
