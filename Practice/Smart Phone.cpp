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
	cin>>n;
	vi v(n);
	for (int i = 0; i < n; ++i) {
		cin>>v[i];
	}

	sort(v.begin(), v.end());
	ll k=n;
	ll ans=0;
	for (int i = 0; i < n; ++i) {
		ans=max(ans,v[i]*k);
		k--;
	}

	cout<<ans;

	return 0;
}
