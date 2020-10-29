#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
 
#define ff first
#define ss second
 
#define ll  long long
#define pii pair<int, int>
#define vi  vector<ll>
 
const int nn = 1000001;
int sieve[nn];
void precompute()
{
    for (int i = 0; i < nn; ++i)
    {
        sieve[i] = i;
    }
 
    for (int i = 4; i < nn; i += 2)
    {
        sieve[i] = 2;
    }
 
    for (ll i = 3; i < nn; i += 2)
    {
        if (sieve[i]==i)
        {
            for (ll j = i * i; j  < nn; j += 2*i)
            {
                if(sieve[j]==j)
                    sieve[j] = i;
            }
        }
    }
}
 
ll t,n,k,temp,tempK,ans;
 
int main() { 
    sync;
    precompute();
    cin >> t;
    while (t--) {
        cin>>n>>k;
        if(n&1){
            ans = n + sieve[n] + 2*(k-1);
        } else {
            ans = n + 2*k;
        }

        cout << ans << '\n';
    }
 
    return 0;
}
