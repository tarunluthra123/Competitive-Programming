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
    ll a, b, c;
    cin >> a >> b >> c;
    ll m = max(a, max(b, c));
    ll cn = 0;
    cn = (a == m) + (b == m) + (c == m);
    if (cn == 1) {
        cout << "NO";
        return ;
    }
    ll q = min(a,min(b,c));
    cout << "YES\n";
    cout << m << " " << q << " " << 1;
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
