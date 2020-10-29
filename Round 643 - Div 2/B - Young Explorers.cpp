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

        sort(v.begin(), v.end());
        ll ans=0;
        ll c=0;
        for (int i = 0; i < n; ++i) {
            c++;
            if(c>=v[i]){
                //New group starts from here
                c=0;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
