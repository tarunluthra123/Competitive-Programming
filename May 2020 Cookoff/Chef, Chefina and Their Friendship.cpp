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

bool check(const unordered_map<char,ll>&m){
    for(auto p:m){
        if(p.ss&1)
            return 0;
    }
    return 1;
}

void solve(){
    unordered_map<char,ll> freq;
    string s;
    cin>>s;
    int n = s.size();
    int ans=0;
    for (int i = 0; i < n; ++i) {
        if(check(freq) and i>0 and i%2==0){
            // cout<<"i = " << i << endl;
            int j = i/2;
            // cout<<"j="<<j<<endl;
            string a = s.substr(0,j);
            string b = s.substr(j,j);
            // cout<<a<<" " << b << endl;
            if(a==b){
                int q = n-i;
                string c = s.substr(i,q/2);
                string d = s.substr(i+q/2,q/2);
                if(c==d)
                    ans++;
                // int x=i*2;
                // for (int j = i; j < x; ++j) {
                //     freq[s[j]]++;
                // }
                // i=x-1;
                // continue;
            }
        }
        freq[s[i]]++;
    }
    cout<<ans<<endl;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
