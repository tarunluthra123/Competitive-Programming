#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int

void solve() {
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] & 1)
            odd++;
        else
            even++;
    }
    cout << min(odd, even);
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
