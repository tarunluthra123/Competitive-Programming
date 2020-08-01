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
    ll n;
    cin >> n;
    vi v(n);

    unordered_set<ll> h;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        h.insert(v[i]);
    }

    ll x = v[0], y = v[n - 1];

    for (int i = 1; i < n; ++i) {
        // x |= v[i];
        if ((x | v[i]) == x) {
            cout << "NO";
            return;
        }
        x |= v[i];
        if ((y | v[n - i - 1]) == y) {
            cout << "NO";
            return;
        }
        y |= v[n - i - 1];
        // h.insert(x);
    }

    cout << "YES";
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
