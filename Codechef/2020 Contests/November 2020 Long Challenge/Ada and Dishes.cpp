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

#define hmap  unordered_map
#define hset  unordered_set
#define maxpq priority_queue<ll>
#define minpq priority_queue<ll,vi,greater<ll>>

template<typename T, typename U>
inline bool operator&(const T &s, U x) {return (s.find(x) != s.end());}

void solve() {
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << v[0];
        return;
    }
    if (n == 2) {
        cout << max(v[0], v[1]);
        return;
    }

    sort(v.begin(), v.end());
    vi freq(6);
    for (int i = 0; i < n; ++i) {
        freq[v[i]]++;
    }
    ll ans = 0;
    vi one, two;
    one.pb(v[n - 1]);
    two.pb(v[n - 2]);
    ll q = v[n - 1];
    ll w = v[n - 2];


    for (int i = n - 3; i >= 0; i--) {
        if (q < w) {
            one.pb(v[i]);
            q += v[i];
        }
        else {
            w += v[i];
            two.pb(v[i]);
        }
    }

    ans = max(q, w);
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
