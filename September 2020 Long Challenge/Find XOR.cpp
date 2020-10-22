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

void solve() {
    ll n;
    cin >> n;
    bool flag = 0;

    //Get sum of sequence
    cout << 1 << " " << (1ll << 20) << '\n';
    cout.flush();
    ll totalSum;
    cin >> totalSum;
    totalSum -= (1ll << 20) * n;
    ll ans = 0;

    vi save(20, 0);
    for (ll bit = 0; bit <= 18; bit++) {
        ll num = (1ll << bit);
        cout << 1 << " " << num << '\n';
        cout.flush();
        ll x;
        cin >> x;
        ll diff = (totalSum - x) / num;
        save[bit] = (n + diff) / 2;
        if (save[bit] & 1) {
            ans |= num;
        }
    }

    ll sum = 0;
    for (ll i = 0; i <= 18; i++) {
        sum += (1ll << i) * save[i];
    }

    ll diff = (totalSum - sum) / (1ll << 19);
    save[19] = diff;
    if (diff & 1) {
        ans |= (1ll << 19);
    }

    cout << 2 << " " << ans << "\n";
    cout.flush();

    ll x;
    cin >> x;
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
