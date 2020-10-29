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
        if(n<4){
            cout<<-1<<'\n';
            continue;
        }
        for(ll i=(n&1)?n:n-1;i>=1;i-=2)
            cout<<i<<" " ;
        cout<<"4 2 ";
        for(ll i=6;i<=n;i+=2)
            cout<<i<<" ";
        cout<<endl;

    }

    return 0;
}
