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
    ll n;
    cin>>n;
    vi v(n);
    ll m=INT_MIN;
    map<ll,ll> freq;
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        m=max(m,v[i]);
        freq[v[i]]++;
    }

    if(freq[m]>=2){
        cout<<"NO";
        return;
    }

    for(auto x:freq){
        if(x.ss>=3){
            cout<<"NO";
            return;
        }
    }

    vi ans(n);
    ll i=0,j=n-1;
    for(auto x:freq){
        ll p = x.ff;
        ll q = x.ss;
        if(q==1){
            ans[i++]=p;
        } else {
            ans[i++]=p;
            ans[j--]=p;
        }
    }

    cout<<"YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " " ;
    }

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
