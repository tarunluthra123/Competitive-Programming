#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define inf 1e18

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
    ll n, eggs, bars, omel, milk, cake;
    cin >> n >> eggs >> bars >> omel >> milk >> cake;
    ll egg_req = 2, bar_req = 3;
    ll ans = inf;
    if (omel > milk) {
        swap(omel, milk);
        swap(egg_req, bar_req);
        swap(eggs, bars);
    }

    for (int i = 0; i <= n; i++) {
        if (eggs >= i and bars >= i) {
            ll used_omel = min(n - i, (eggs - i) / egg_req);
            ll used_milk = min(n - i - used_omel, (bars - i) / bar_req);
            if (i + used_milk + used_omel == n) {
                ans = min(ans, i * cake + used_omel * omel + used_milk * milk);
            }
        }
    }

    if (ans == inf)
        ans = -1;

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
