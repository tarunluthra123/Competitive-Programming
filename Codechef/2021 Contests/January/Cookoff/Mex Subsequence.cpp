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
    ll n; cin >> n;
    vi a(n + 1), dp(n + 1), ind(n + 1), prefdp(n + 1);

    map <ll, ll> m1;
    ll mex = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 0;
        ind[i] = 0;
        prefdp[i] = 0;
        m1[a[i]]++;
    }

    while (m1[mex] != 0) {
        mex++;
    }

    if (mex == 0) {
        ll ans = 1LL << (n - 1);
        cout << ans;
        return;
    }

    multiset <ll> index;
    for (int i = 0; i < mex; i++) {
        index.insert(0);
    }


    dp[0] = prefdp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (a[i] < mex) {
            auto itr = index.find(ind[a[i]]);
            index.erase(itr);
            ind[a[i]] = i;
            index.insert(ind[a[i]]);
        }

        int prev_ind = (*index.begin());
        if (prev_ind != 0) {
            dp[i] = prefdp[prev_ind - 1];
        }
        prefdp[i] = (prefdp[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n];
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
