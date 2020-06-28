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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        unordered_map<char,int> m;
        for (int i = 0; i < n; ++i) {
            m[s[i]]++;
        }
        while(q--){
            int c;
            cin>>c;
            ll ans=0;
            for(char ch='a';ch<='z';ch++){
                ans += m[ch]>c?m[ch]-c:0;
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}
