#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9+1

struct item{
    int wt;
    int val;
};

int knapsack(const vector<item> &arr,int n,int W) {
    int maxVal = n*1000;
    int dp[n+1][maxVal+1];

    for(int val=0; val <= maxVal ; val++) {
        dp[1][val] = inf;
    }

    dp[1][0] = 0;
    dp[1][arr[1].val] = arr[1].wt;

    for(int i=2;i<=n;i++) {
        for(int v=0; v <=maxVal ; v++ ) {
            dp[i][v] = dp[i-1][v];
            if(arr[i].val > v)
                continue;
            dp[i][v] =min(dp[i][v], arr[i].wt + dp[i-1][v-arr[i].val]);
        }
    }

    int ans = 0;

    for(int x=0;x<=maxVal;x++) {
        if(dp[n][x] <= W) {
            ans = x;
        }
    }

    return ans;
}

int main() {
    int n,W;
    cin >> n >> W;
    vector<item> v(n+1);

    for(int i=1;i<=n;i++) {
        cin >> v[i].wt >> v[i].val; 
    }

    cout << knapsack(v,n,W);

    return 0;
}
