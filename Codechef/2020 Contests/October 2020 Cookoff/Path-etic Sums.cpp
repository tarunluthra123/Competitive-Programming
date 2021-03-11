#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define inf 2000000000

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

template<typename T>
inline bool operator&(const T &s, ll x) {return (s.find(x) != s.end());}

map<ll, vector<ll>> g;
map<ll, ll> m;


void dfs(ll u, bool flag) {
	if (m & u)
		return;
	if (flag)
		m[u] = 1;
	else
		m[u] = 2;
	flag = !flag;
	for (ll v : g[u]) {
		dfs(v, flag);
	}
}

void solve() {
	ll n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		ll u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1, true);

	for (int i = 1; i <= n; i++) {
		cout << m[i] << " ";
	}
}

int main() {
	sync;
	int testCases, t = 1;
	cin >> testCases;
	while (testCases--) {
		// cout << "Case #" << t++ << ": ";
		solve();
		cout << '\n';

		g.clear();
		m.clear();
	}

	return 0;
}
