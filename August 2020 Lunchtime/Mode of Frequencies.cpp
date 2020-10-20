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
    unordered_map<ll, ll> freq, m;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        freq[x]++;
    }

    for (pii x : freq) {
        m[x.ss]++;
    }

    ll maxFreq = 0;

    for (pii x : m) {
        maxFreq = max(maxFreq, x.ss);
    }

    vi res;

    for (pii x : m) {
        if (x.ss == maxFreq) {
            res.pb(x.ff);
        }
    }
    sort(res.begin(), res.end());
    cout << res[0];
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
