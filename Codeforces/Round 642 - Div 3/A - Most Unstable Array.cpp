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
        ll n,m;
        cin>>n>>m;
        if(n==1){
            cout<<0<<'\n';
        } else if(n==2){
            cout<<m<<'\n';
        } else {
            cout << 2*m << '\n';
        }
    }

    return 0;
}
