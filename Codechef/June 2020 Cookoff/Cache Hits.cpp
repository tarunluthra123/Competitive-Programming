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

void solve() {
    ll n,b,m;
    cin>>n>>b>>m;

    ll ans=0;
    ll curr=-1;

    ll x;
    cin>>x;
    curr = x/b;
    ans=1;

    for (int i = 1; i < m; ++i) {
        cin>>x;
        if(x/b!=curr){
            curr = x/b;
            ans++;
        }
    }

    cout<<ans;
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
