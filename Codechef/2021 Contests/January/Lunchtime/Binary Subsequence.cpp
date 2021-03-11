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

ostream& operator<<(ostream &cout, vi &v) {cout << "["; for (int i = 0; i < v.size(); ++i) {cout << v[i]; cout << (i < v.size() - 1 ? ", " : "]\n");} return cout;}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vi one(n + 1), zero(n + 1);
    for (int i = 1; i <= n; ++i) {
        one[i] = one[i - 1] + (s[i - 1] == '1');
    }
    zero[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        zero[i] = zero[i + 1] + (s[i] == '0');
    }
    ll ans = n;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, one[i] + zero[i]);
    }

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
