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

ostream& operator<<(ostream &cout, vi &v) {cout << "["; for (int i = 0; i < v.size(); ++i) {cout << v[i]; cout << (i < v.size() - 1 ? ", " : "]\n");}}

void solve() {
    ll n, k, x, y;
    cin >> n >> k >> x >> y;
    if (x == y) {
        cout << n << " " << n;
        return;
    }
    bool sw = false;
    if (x > y) {
        sw = true;
        swap(x, y);
    }

    pii ans;
    if (k % 4 == 0)
        ans = {0, y - x};
    else if (k % 4 == 1)
        ans = {n + x - y, n};
    else if (k % 4 == 2)
        ans = {n, n + x - y};
    else
        ans = {y - x, 0};

    if (sw)
        swap(ans.ff, ans.ss);

    cout << ans.ff << " " << ans.ss;
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
