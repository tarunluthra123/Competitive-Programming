//https://codeforces.com/contest/1324/problem/D
#include <bits/stdc++.h>
using namespace std;

#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long

int main()
{
    sync;

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
    {
        c[i] = b[i] - a[i];
    }

    sort(c.begin(), c.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll idx = lower_bound(c.begin() + i + 1, c.end(), -c[i]) - c.begin();
        ans += idx - i - 1;
    }

    cout << ans << "\n";

    return 0;
}
