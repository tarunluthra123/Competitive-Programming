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

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll open=0,close=0;
    ll ans=0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='(')
            open++;
        else
            close++;
        if(close>open){
            close--;
            ans++;
        }
    }
    cout<<ans;
}

int main() {
    sync;
    int testCases, t = 1;
    cin >> testCases;
    while (testCases--) {
        // cout << "Case #" << t++ << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}