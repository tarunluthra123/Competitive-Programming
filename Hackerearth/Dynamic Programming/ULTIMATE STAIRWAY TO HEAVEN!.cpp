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
	ll n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vi dp(n);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		ll k = v[i];
		for (int j = 1; j <= k and i + j < n; ++j) {
			dp[i + j] += dp[i] % MOD;
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	cout << dp[i] << " ";
	// }

	cout << dp[n - 1];

	return 0;
}
