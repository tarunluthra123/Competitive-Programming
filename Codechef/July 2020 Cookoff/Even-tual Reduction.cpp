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

template<typename T>
inline bool operator&(const T &s, int x) {return (s.find(x) != s.end());}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> p;
    for (int i = 0; i < n; ++i) {
        if (p & s[i]) {
            p.erase(s[i]);
        } else {
            p.insert(s[i]);
        }
    }

    if (p.size() > 0) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
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
