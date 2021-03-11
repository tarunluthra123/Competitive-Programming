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

#define hmap  unordered_map
#define hset  unordered_set
#define maxpq priority_queue<ll>
#define minpq priority_queue<ll,vi,greater<ll>>

template<typename T, typename U>
inline bool operator&(const T &s, U x) {return (s.find(x) != s.end());}

map<ll, vi> g;

pii dfs(ll node) {
	ll size = 1;
	ll mex = 0;
	for (ll u : g[node]) {
		pii curr = dfs(u);
		mex = max(mex, curr.ff);
		size += curr.ss;
	}

	return {mex + size, size};
}

void solve() {
	ll n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		ll parent;
		cin >> parent;
		g[parent].pb(i);
	}

	pii ans = dfs(1);
	cout << ans.ff;
}

void precompute() {}

int main() {
	sync;
	precompute();
	int testCases = 1, t = 1;
	cin >> testCases;
	while (testCases--) {
		// cout << "Case #" << t++ << ": ";
		solve();
		cout << '\n';
		g.clear();
	}

	return 0;
}
