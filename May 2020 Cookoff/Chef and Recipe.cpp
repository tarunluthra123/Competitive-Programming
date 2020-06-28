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


void solve(){
    ll x,n;
    cin>>n;
    unordered_set<ll> freq;
    unordered_set<ll> s;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    for (int i = 0; i < n; ++i) {
        ll j=i+1;
        while(j<n and v[i]==v[j])
            j++;
        if(s.find(v[i])!=s.end()){
            cout<<"NO";
            return;
        }
        s.insert(v[i]);
        if(freq.find(j-i)!=freq.end()){
            cout<<"NO";
            return;
        }
        freq.insert(j-i);
        // cout<<j-i<<endl;
        i=j-1;
    }

    cout<<"YES";
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
        cout<<'\n';
    }
    return 0;
}
