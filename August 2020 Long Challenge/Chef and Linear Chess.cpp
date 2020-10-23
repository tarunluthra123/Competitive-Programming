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
inline bool operator&(const T &s, int x) {return (s.find(x) != s.end());}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi v(n);
    ll ans = inf;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > k) {
            v[i] = -1;
        }
        else if (k % v[i] == 0) {
            v[i] = k / v[i];
            ans = min(ans, v[i]);
        }
    }
    if (ans == inf) {
        cout << -1;
    } else {
        cout << k / ans;
    }
    return;
}

int main() {
    sync;
    int testCases, t = 1;
    cin >> testCases;
    while (testCases--) {
        // cout << "Case #" << t++ << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}
