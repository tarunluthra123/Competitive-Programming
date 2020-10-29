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
        ll n;
        cin>>n;
        vi v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }

        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            ll idx = ((i+v[i]%n)%n+n)%n;
            vis[idx]=true;
        }

        bool ans=1;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]){
                ans=0;
                break;
            }
        }

        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
