#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll knapsackBottomUp(const vector<int> &wts, const vector<int> &prices,int n,int w){
    vector< vector<ll> > dp(n+1, vector<ll>(w+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || w==0){
                dp[i][j] = 0;
            }
            else {
                ll include = 0 ,exclude = 0;
                if(wts[i-1]<=j){
                    include = prices[i-1] + dp[i-1][j-wts[i-1]] ; 
                }

                exclude = dp[i-1][j];

                dp[i][j] = max(include,exclude) ; 
            }
        }
    }

    return dp[n][w];
}

int main() {
    int n,W;
    cin>>n>>W;

    vector<int> w(n),price(n);
    for (int i = 0; i < n; ++i) {
        cin>>w[i]>>price[i];
    }


    cout << knapsackBottomUp(w, price, n , W) << "\n";


    return 0;
}