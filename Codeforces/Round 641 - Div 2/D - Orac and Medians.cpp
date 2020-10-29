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

bool solve(){
    ll n,k;
    cin>>n>>k;
    vi v(n+1);

    bool ok=0;


    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]==k){
            v[i]=1;
            ok=1;
        }
        else if(v[i]>k)
            v[i]=2;
        else
            v[i]=0;
    }


    if(!ok)
        return 0;

    if(n==1)
        return 1;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n and j-i<=2;j++) {
            if(v[i] and v[j])
                return 1;
        }
    }

    return 0;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        bool ans = solve();

        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";

    }

    return 0;
}           
