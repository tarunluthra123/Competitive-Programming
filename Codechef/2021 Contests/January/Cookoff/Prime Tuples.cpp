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

ll nn = 1000006;
vector<bool> sieve;
vi primes;
vi tcp(nn, 0);

void precomputeSieve() {
    sieve.resize(nn);
    sieve[2] = true;
    for (int i = 3; i < nn; i += 2)
        sieve[i] = true;
    primes.pb(2);
    for (ll i = 3; i < nn; i += 2) {
        if (sieve[i]) {
            primes.pb(i);
            for (ll j = i * i; j < nn; j += 2 * i)
                sieve[j] = false;
        }
    }
}

void solve() {
    ll i;
    cin >> i;
    cout << tcp[i];
}

void precompute() {
    precomputeSieve();
    ll lastPrime = 2;
    for (int i = 3; i < tcp.size(); ++i) {
        tcp[i] = tcp[i - 1];
        if (sieve[i]) {
            ll diff = i - lastPrime;
            lastPrime = i;
            if (diff == 2) {
                tcp[i] = tcp[i - 1] + 1;
            }
        }
    }
    // cout << tcp;
}

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
