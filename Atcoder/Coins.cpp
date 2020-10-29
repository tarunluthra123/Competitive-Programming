#include <bits/stdc++.h>
using namespace std;

double dp[3001][3001];
double coins(const vector<double>& v,int i,int x) {
    if(x == 0)
        return 1;
    if(i == 0)
        return 0;
    if(dp[i][x] >= -0.9)
        return dp[i][x];

    return dp[i][x] = v[i]*coins(v,i-1,x-1) + (1-v[i])*coins(v,i-1,x);
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    memset(dp,-1,sizeof dp);

    cout << fixed << setprecision(10) << coins(v,n,(n+1)/2) << "\n";

    return 0;
}