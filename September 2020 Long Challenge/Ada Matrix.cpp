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

void solve() {
    ll n;
    cin >> n;
    vi v(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> v[i];
    }
    vector<bool> b(n);
    for (int i = 0; i < n; ++i) {
        if (v[i] == i + 1)
            b[i] = 1;
        else
            b[i] = 0;
    }
    bool flag = false;
    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (flag)
            b[i] = !b[i];
        if (b[i] == 1)continue;
        else {
            ans++;
            flag = !flag;
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
