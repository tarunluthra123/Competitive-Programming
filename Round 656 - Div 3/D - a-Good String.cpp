#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long int
#define pii pair<ll, ll>
#define vi  vector<ll>

ll ans = 0;

ll check(string s, char ch = 'a') {
    if (s.size() == 1) {
        return 1 - (s[0] == ch);
    }
    ll q = 0;
    for (int i = 0; i < s.size() / 2; ++i) {
        q += 1 - (s[i] == ch);
    }
    q += check(s.substr(s.size() / 2), ch + 1);
    ll u = 0;
    for (int i = s.size() / 2; i < s.size(); ++i) {
        u += 1 - (s[i] == ch);
    }
    u += check(s.substr(0, s.size() / 2), ch + 1);
    // cout << s << " " << min(q, u) << " " << ch << endl;
    return min(q, u);
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ans = check(s);
    cout << ans;
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
