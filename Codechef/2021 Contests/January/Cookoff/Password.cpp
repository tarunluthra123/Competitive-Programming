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
    string s;
    cin >> s;
    if (s.size() < 10) {
        cout << "NO";
        return;
    }
    // if (!isalpha(s[0]) || !islower(s[0]) || !isalpha(s.back()) || !islower(s.back())) {
    //     cout << "NO2";
    //     return;
    // }
    bool cap = false, num = false, sym = false, wrong = false, low = false;
    set<char> sp {'@', '#', '%', '&', '?' };
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            num = true;
        else if (s[i] >= 'A' and s[i] <= 'Z')
            cap = true;
        else if (sp & s[i])
            sym = true;
        else if (s[i] >= 'a' and s[i] <= 'z')
            low = true;
        else
            wrong = true;
    }
    if (s[0] >= 'a' and s[0] <= 'z')
        low = true;
    if (s.back() >= 'a' and s.back() <= 'z')
        low = true;
    if (wrong) {
        cout << "NO";
        return;
    }
    if (num && cap && sym && low) {
        cout << "YES";
        return;
    }
    cout << "NO";
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
