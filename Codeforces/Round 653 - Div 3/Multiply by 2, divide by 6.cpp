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
    if(n==1){
        cout<<0;
        return;
    }
    ll two=0;
    while(n%2==0){
        n/=2;
        two++;
    }
    ll three=0;
    while(n%3==0){
        n/=3;
        three++;
    }
    if(n>1){
        cout<<-1;
        return;
    }
    if(two>three){
        cout<<-1;
        return;
    }
    ll ans = three + three - two;
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