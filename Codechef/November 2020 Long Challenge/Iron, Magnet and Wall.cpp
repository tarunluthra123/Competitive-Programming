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

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string new_s = "";

    //sheet reduces the magnetic strength by an additional one so simple
    //add an extra position with sheet. This will automatically reduce the
    //strength by one.
    for (auto i : s)
    {
        if (i == ':')
        {
            new_s += i;
        }
        new_s += i;
    }
    s = new_s;

    queue<ll> qi, qm;
    int j = 0;
    int ans = 0;

    for (char i : s) {
        if (i == 'I') {
            while (!qm.empty() && qm.front() + k < j) {
                qm.pop();
            }

            if (!qm.empty()) {
                ans++;
                qm.pop();
            }
            else  {
                qi.push(j);
            }
        }
        else if (i == 'M') {
            while (!qi.empty() && qi.front() + k < j) {
                qi.pop();
            }

            if (!qi.empty()) {
                ans++;
                qi.pop();
            }
            else   {
                qm.push(j);
            }
        }
        else if (i == 'X')   {
            while (!qm.empty()) {
                qm.pop();
            }
            while (!qi.empty()) {
                qi.pop();
            }
        }

        j++;
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
