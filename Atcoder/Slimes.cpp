#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (ll)1e15
ll dp[405][405];

ll sum(const vector<ll>& v,int s,int e){
    ll ans = 0 ;
    for(int i=s;i<=e;i++){
        ans += v[i];
    }
    return ans ;
}

ll slimes(const vector<ll>& v,int s,int e) {
	if(s>=e)
		return 0;
	if(dp[s][e] != -1)
		return dp[s][e];

	ll ans = inf;

	for(int k=s;k<e;k++) {
		ll currentSum = sum(v,s,k) + sum(v,k+1,e);
		ans = min(ans, currentSum + slimes(v,s,k) + slimes(v,k+1,e));
	}

	return dp[s][e] = ans;
}

int main() {
    int n;
    cin>>n;
    vector<ll> v(n); 
    for (int i = 0; i < n; ++i) {
    	cin>>v[i];
    }

    memset(dp,-1,sizeof dp);

    cout << slimes(v,0,n-1) << endl;

    return 0;
}
