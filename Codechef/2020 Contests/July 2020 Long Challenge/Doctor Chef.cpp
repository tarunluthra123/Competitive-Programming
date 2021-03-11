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
    ll n,x;
    cin>>n>>x;
    vi v(n);
    multiset<ll> s;
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        s.insert(v[i]);
    }

    ll c=0;
    ll ans=0;
    while(c<n and !s.empty()){
        if(x < *(s.begin())){
            ans++;
            x=x<<1;
            continue;
        }
        auto it = s.lower_bound(x);
        auto temp = it;
        temp--;
        if(it == s.end()){
            //x is greater than largest element
            s.erase(temp);
            c++;
        }
        else if(*it == x){
            s.erase(it);
            c++;
            x = x<<1;
        }
        else if(*temp <= x/2){
            //Do nothing, cover this later
            x = x<<1;
        }
        else {
            c++;
            x = *temp * 2;
            s.erase(temp);
        }
        ans++;
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
