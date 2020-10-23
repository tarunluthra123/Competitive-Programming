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
    string s, p;
    cin >> s >> p;
    unordered_map<char, int> h;
    for (int i = 0; i < s.size(); ++i) {
        h[s[i]]++;
    }
    for (int i = 0; i < p.size(); ++i) {
        h[p[i]]--;
    }

    string out = "";
    for (char c = 'a'; c <= 'z'; c++) {
        ll x = h[c];
        string tmp = "";
        for (int i = 0; i < x; ++i) {
            tmp += c;
        }
        if (c == p[0]) {
            string x = p + tmp;
            string y = tmp + p;
            if (x < y) {
                out += x;
            }
            else {
                out += y;
            }
        }
        else
            out += tmp;
    }
    cout << out;
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
