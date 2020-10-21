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
    ll n;
    cin >> n;
    vi v(n);
    ll one = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        one += v[i];
    }
    if (one == 1) {
        cout << 0;
        return;
    }
    ll x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            x = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 1) {
            y = i;
            break;
        }
    }

    ll ans = 0;

    for (int i = x; i <= y; i++) {
        if (v[i] == 0)
            ans++;
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
