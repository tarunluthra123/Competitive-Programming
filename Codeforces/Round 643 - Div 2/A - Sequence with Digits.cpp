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
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n,k;
        cin>>n>>k;
        for (int i = 0; i < k-1; ++i) {
            ll p=0,q=9,r=n;
            while(r){
                p=max(p,r%10);
                q=min(q,r%10);
                r/=10;
            }
            n+=p*q;
            if(p*q==0)
                break;
        }
        cout<<n<<'\n';
    }

    return 0;
}
