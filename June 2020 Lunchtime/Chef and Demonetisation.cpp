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
    ll s,n;

    cin>>s>>n;
    ll ans=0;
    if(s&1){
        ans=1;
        s--;
    }
    if(n&1)n--;
    if(s>=n){
        ans += s/n;
        s = s%n;
    }
    if(s!=0)
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
