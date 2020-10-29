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
    ll idx = 0;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i != 0 and v[i] != v[0]) {
            idx = i;
        }
    }
    if (idx == 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << 1 << " " << idx + 1 << '\n';
    for (int i = 0; i < n; ++i) {
        if (i == 0 or i == idx) {
            continue;
        }
        if (v[i] == v[0]) {
            cout << i + 1 << " " << idx + 1 << '\n';
        }
        else {
            cout << "1 " << i + 1 << '\n';
        }
    }
}

int main() {
    sync;
    int testCases, t = 1;
    cin >> testCases;
    while (testCases--) {
        // cout << "Case #" << t++ << ": ";
        solve();
    }

    return 0;
}
