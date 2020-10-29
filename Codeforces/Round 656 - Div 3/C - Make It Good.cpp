#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

void solve() {
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    bool inc = true;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] > v[i - 1]) {
            inc = false;
        } else if (!inc and v[i] < v[i - 1]) {
            break;
        }
        ans++;
    }
    ans++;
    ans = n - ans;
    ans = max(ans, 0ll);
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
