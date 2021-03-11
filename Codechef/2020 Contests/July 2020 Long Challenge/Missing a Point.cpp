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
    n=4*n-1;
    // unordered_map<ll,ll> x,y;
    ll x=0,y=0;
    while(n--){
        ll a,b;
        cin>>a>>b;
        x=x^a;
        y=y^b;
    }

    cout<<x<<" "<<y;
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
