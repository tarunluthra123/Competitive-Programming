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

int main() { 
    sync;
    ll n;
    cin>>n;
    vi v(n+1);
    for (int i=1;i<=n;i++) {
        cin>>v[i];
    }

    vi suffixGcd(n+1);
    suffixGcd[n] = v[n];
    for (int i=n-1;i>=1;i--) { 
        suffixGcd[i] = __gcd(suffixGcd[i+1], v[i]);
    }

    vi b(n+1);
    for(int i=1;i<n;i++){
        b[i] = (v[i]*suffixGcd[i+1])/__gcd(v[i],suffixGcd[i+1]);
    }

    ll ans = b[1];
    for (int i=2;i<b.size();i++){
        ans = __gcd(ans, b[i]);
    }

    cout<<ans;

    return 0;
}
