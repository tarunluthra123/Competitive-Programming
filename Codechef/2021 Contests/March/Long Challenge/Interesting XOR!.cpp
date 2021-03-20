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

string lltos(ll n) {
    string ans = "";
    while (n) {
        if (n & 1)
            ans += "1";
        else
            ans += "0";
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    ll c;
    cin >> c;
    string s = lltos(c);


    string a = "", b = "";
    bool first = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            a += '1';
            b += '1';
        }
        else {
            if (first) {
                a += "0";
                b += "1";
            }
            else {
                a += "1";
                b += "0";
                first = true;
            }
        }
    }

    ll p = stoll(a, 0, 2);
    ll q = stoll(b, 0, 2);
    cout << p*q;
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
