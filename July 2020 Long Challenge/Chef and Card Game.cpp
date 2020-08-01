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

ll sumOfDigit(ll m){
    ll s=0;
    while(m>0){
        s += m%10;
        m/=10;
    }
    return s;
}

void solve() {
    ll n;
    cin>>n;
    ll a=0;
    ll b=0;
    while(n--){
        ll x,y;
        cin>>x>>y;
        x=sumOfDigit(x);
        y=sumOfDigit(y);
        if(x==y){
            a++;b++;
        } else if(x>y){
            a++;
        } else {
            b++;
        }
    }
    if(a==b){
        cout<<2<< " " << b;
    }
    else if(a>b){
        cout<<0<<" " <<a;
    }else{
        cout<<1<<" " << b;
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
