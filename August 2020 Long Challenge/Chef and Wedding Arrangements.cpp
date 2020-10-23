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

template<typename T, typename U>
inline bool operator&(const T &s, U x) {return (s.find(x) != s.end());}

ll n, k;
vi arr;
vi memo;

ll dp(ll l) {
    if (l >= n)
        return 0;

    ll &ans = memo[l];

    if (ans != -1)
        return ans;

    ans = INT_MAX;
    ll g = 0, tmp = 0;
    hash<ll, ll> f;

    for (int i = l; i < n; i++)
    {
        if (f[arr[i]] == 1)
            tmp++;

        f[arr[i]]++;

        if (f[arr[i]] > 1)
            g++;

        ans = min(ans, g + tmp + ((i + 1 < n) ? k : 0) + dp(i + 1));
    }

    return ans;
}

void solve() {
    cin >> n >> k;

    arr.clear();
    memo.clear();
    arr.resize(n);
    memo.assign(n, -1);

    for (auto &x : arr)
        cin >> x;

    cout << k + dp(0) ;
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
