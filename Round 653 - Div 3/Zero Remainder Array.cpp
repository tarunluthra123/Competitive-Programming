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
    ll n,k;
    cin>>n>>k;
    map<ll,ll> m;
    ll x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        x = x%k;
        if(x!=0)
            m[x]++;
    }
    ll ans=0;
    for(auto p:m){
        ans = max(ans, p.ss*k - p.ff);
    }

    if(ans>0)
        ans++;

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