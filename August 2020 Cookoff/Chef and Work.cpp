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

#define hash unordered_map
#define hset unordered_set

template<typename T, typename U>
inline bool operator&(const T &s, U x) {return (s.find(x) != s.end());}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll ans = 1, s = 0;

    for (int i = 0; i < n; ++i) {
        if (v[i] > k) {
            cout << -1;
            return;
        }
        if (s + v[i] <= k) {
            s += v[i];
        } else {
            ans++;
            s = v[i];
        }
    }
    cout << ans;
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
