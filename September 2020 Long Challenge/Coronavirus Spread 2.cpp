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
#define pff pair<double, double>

#define hash unordered_map
#define hset unordered_set

template<typename T, typename U>
inline bool operator&(const T &s, U x) {return (s.find(x) != s.end());}

void solve() {
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    map<pii, vi> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                ll t = ( (j - i) * 120) / (v[i] - v[j]);
                ll x = i * 120 + v[i] * t;
                mp[ {t, x}].pb(i);
                mp[ {t, x}].pb(j);
            }
        }
    }

    ll best = n;
    ll worst = 0;

    for (int i = 0; i < n; ++i) {
        vector<bool> infected(n);
        infected[i] = true;
        for (auto x : mp) {
            bool spread = false;
            for (ll person : x.ss) {
                if (infected[person]) {
                    spread = true;
                }
            }

            if (spread) {
                for (ll person : x.ss) {
                    infected[person] = true;
                }
            }
        }

        ll c = 0;

        for (int i = 0; i < n; ++i) {
            if (infected[i]) {
                c++;
            }
        }

        best = min(best, c);
        worst = max(worst, c);
    }

    cout << best << " " << worst;
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
