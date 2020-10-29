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

int main() {
    sync;
    ll n;
    cin >> n;
    ll r = n / 2;
    ll f = 1;
    for (ll i = 1; i <= n; i++) {
        f *= i;
    }
    ll den = r * r * 2;
    cout << (f / den);

    return 0;
}
