#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    vector<bool> dp(k+1,0);
    for (int i = 0; i <= k; ++i) {
        for(int move : v) {
            if(move > i) 
                continue;
            if(dp[i-move] == 0)
                dp[i] = 1;
        }
    }

    // for (int i = 0; i < dp.size(); ++i)
    // {
    //     cout << dp[i] << " ";
    // }





    if(dp[k]) {
        cout << "First";
    } else {
        cout << "Second";
    }

    return 0;
}