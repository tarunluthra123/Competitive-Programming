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

bool myCompare(pii a,pii b){
    if(a.ss==b.ss){
        return a.ff < b.ff;
    }
    else {
        return a.ss > b.ss;
    }
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    map<ll,ll> b;
    for (int i = 0; i < n; ++i) {
        ll j=0;
        while(v[i]>0){
            if(v[i]&1)
                b[j]++;
            v[i]>>=1;
            j++;
        }
    }


    ll ans=0;
    vector<pii> arr;

    for(auto x:b){
        // cout<<x.ff << " " << x.ss << endl;
        ll cont = x.ss*(ll)(1<<(int)x.ff);
        arr.pb({x.ff,cont});
    }
    // cout<<endl;

    // for(int i=31;i>=0;i--){
    //     if(b[i]){
    //         ll cont = b[i]*(1<<i);
    //         arr.pb({i,cont});
    //     }
    // }

    // cout << "size="<<arr.size() << endl;

    sort(arr.begin(), arr.end(), myCompare);
    // for (int i = 0; i < arr.size(); ++i) {
    //     cout<<arr[i].ff << " " << arr[i].ss << endl;
    // }
    ll i=0;
    while(k>0 and i<arr.size()){
        ans += (1<<arr[i].ff);
        i++;
        k--;
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
