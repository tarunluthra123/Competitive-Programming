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
    long long N , M , x , y , f , s;
    cin >> N  >> M >> x >> y ;

    if (N == 1 && M == 1) {
        cout << x << endl ;
        return ;
    }

    long long lim = min(2 * x, y) ;
    x = min(x, y) ;

    if (lim < x) {
        f = lim ;
        s = 0 ;
    }
    else {
        f = x ;
        s = lim - x ;
        if (f < s) {
            swap(f, s) ;
        }
    }

    long long half = M / 2 ;
    long long ans = 0 ;

    ans = half * f + half * s ;
    ans *= N ;

    if (M & 1) {
        ans += (N / 2) * f + (N / 2) * s + (N % 2) * f ;
    }
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
