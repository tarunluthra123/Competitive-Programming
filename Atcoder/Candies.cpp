#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define MOD 1000000007

int candies(const vector<int>& v, int k, int n) {
	ll dp[n+2][k+2];
	for (int j = 0; j <= k; ++j) {
		dp[1][j] = (j > v[1]) ? 0 : 1 ;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			if(j==0) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = ((dp[i][j-1] + dp[i-1][j])%MOD + MOD - ((j-v[i]-1>=0) ? dp[i-1][j-v[i]-1] : 0)) % MOD;
			}
		}
	}


	return dp[n][k];
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) {
    	cin >> v[i];
    }

    cout << candies(v,k,n);

    return 0;
}
