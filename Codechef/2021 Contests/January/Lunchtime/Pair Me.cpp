#include <bits/stdc++.h>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  long long int

void solve() {
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[2] == a[0] + a[1]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
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
