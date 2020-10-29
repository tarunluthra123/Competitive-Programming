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

const ll nn = 500005;

ll dp[nn];


int main() { 
    sync;
    
    dp[0]=0;
    dp[1]=8;
    for (int i = 2; i <= nn/2; ++i) {
        ll k = 2*i+1;
        ll x = 2*k + 2*(k-2);
        dp[i] = dp[i-1]+x*i;
    }

    // for (int i = 0; i < 20; ++i) {
    //     cout << dp[i] << " ";
    // }

    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin>>n;
        n/=2;
        cout<<dp[n]<<'\n';
    }



    return 0;
}
