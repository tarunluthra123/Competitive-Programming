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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.size(); i += 4) {
        int x = 0;
        if (s[i] == '1') {
            x = 8;
        }
        if (s[i + 1] == '1') {
            x += 4;
        }
        if (s[i + 2] == '1') {
            x += 2;
        }
        if (s[i + 3] == '1') {
            x += 1;
        }
        char c = x + 'a';
        ans += c;
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
