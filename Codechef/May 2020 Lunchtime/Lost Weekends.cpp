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
        int n=5;
        vi v(n);
        ll s=0;
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
            s+=v[i];
        }

        ll p;
        cin>>p;

        if(s*p > 120){
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }

    }

    return 0;
}
