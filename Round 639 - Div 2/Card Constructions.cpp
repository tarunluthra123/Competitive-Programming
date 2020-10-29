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

ll f(ll h){
    ll num = 3*h*h + h;
    return num/2;
}

ll ssearch(ll n){
    ll s=0;
    ll e=n;
    ll mid,ans=n;
    while(s<=e){
        mid = s+e>>1;
        if(f(mid)<=n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

ll solve(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>=2){
        // cout<<"n="<<n<<endl;
        ll x=ssearch(n);
        ans++;
        n-=f(x);
    }
    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll ans=solve();
        cout<<ans<<'\n';
    }

    return 0;
}
