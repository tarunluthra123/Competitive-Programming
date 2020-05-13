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
        ll n,x;
        cin>>n;
        vi sum(n+1);
        sum[0]=0;
        vi freq(n+1);
        for (int i = 0; i < n; ++i) {
            cin>>x;
            sum[i+1]=sum[i]+x;
            freq[x]++;
        }

        ll ans=0;

        for (int i = 0; i < n; ++i) {
            for (int j = i+2; j < n+1; ++j) {
                ll x=sum[j]-sum[i];
                // cout<<"x = "<<x<<endl;
                if(x<freq.size()){
                    ans += freq[x];
                    freq[x]=0;
                }
                // if(freq[x])
                //     cout<<"yep"<<freq[x]<<"\n";
            }
        }

        cout<<ans<<'\n';

    }

    return 0;
}
