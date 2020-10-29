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
        string s;
        cin>>s;
        ll c=0;
        for(int i=0;i<n;i++){
            c+=(s[i]=='1');
        }
        ll res = c;
        for(int i=0;i<k;i++){
            ll curr = 0,cost=0;
            for(int j=i;j<n;j+=k){
                curr = max((ll)0,curr) + (s[j] == '1'?1:-1);
                cost = max(curr,cost);
            }
 
            res = min(res, c-cost);
        }
 
        cout<<res<<endl;
    }
    
 
    return 0;
}
