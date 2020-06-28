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
    ll n,m,x;
    cin>>n>>m;
    // multiset<ll> s;
    unordered_map<ll,ll> f;

    ll ans=0;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        f[x]++;
        if(x>m)
            ans++;
    }

    if(m==1){
        cout<<n;
        return;
    }

    bool ok=0;
    ll temp = m-1;
    while(f[temp]){
        ok=1;
        ans+=f[temp];
        temp--;
    }

    if(ok==0||temp!=0){
        cout<<-1;
        return;
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
