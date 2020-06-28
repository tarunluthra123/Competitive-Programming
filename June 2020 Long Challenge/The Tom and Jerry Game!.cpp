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

void solve(){
	ll n;
	cin>>n;
	ll temp = n;
	ll k=0;
	while(temp%2==0){
		temp=temp>>1;
		k++;
	}
	ll ans = (1ll<<(k+1));
	ans = n/ans;
	cout<<ans<<'\n';
}

int main() { 
	sync;
	int testCases;
	cin >> testCases;
	while (testCases--) {
		solve();
	}

	return 0;
}
