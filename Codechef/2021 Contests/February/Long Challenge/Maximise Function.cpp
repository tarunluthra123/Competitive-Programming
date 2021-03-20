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

void solve() {
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = a.back() - a[0] + (a.back() - a[1]) + (a[1] - a[0]);
    for (int i = 2; i <= n - 2; i++) {
        ll y = a[i];
        ll p = abs(a.back() - y) + abs(y - a[0]);
        ans = max(ans, a.back() - a[0] + p);
    }
    cout << ans;
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
    }

    return 0;
}
