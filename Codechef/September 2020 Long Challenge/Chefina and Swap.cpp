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

ll nc2(ll n) {
    return n * (n - 1) / 2;
}

ll findX(ll n) {
    long double m = n;
    return (ll)((-2.0 + sqrt(4.0 + 8 * (m * m + m))) / 4.0 );
}

void solve() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0;
        return;
    }

    ll x = findX(n);
    ll ans = n - x;
    if (x * (x + 1) / 2 == sum / 2)
        ans += nc2(x) + nc2(n - x);

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
