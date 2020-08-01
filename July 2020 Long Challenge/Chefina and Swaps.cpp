#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

#define ff first
#define ss second

#define ll  long long
#define pii pair<ll, ll>
#define vi  vector<ll>
#define inf INT_MAX

void solve() {
    ll n;
    cin>>n;
    ll xorr=0,x;
    ll m1=inf,m2=inf;

    unordered_set<ll> tmp,hash;
    multiset<ll> s1,s2;

    vi arr;

    for (int i = 0; i < n; ++i) {
        cin>>x;
        // xorr=xorr^x;
        if(tmp.find(x)==tmp.end())
            tmp.insert(x);
        else {
            tmp.erase(x);
            s1.insert(x);
            arr.pb(x);
        }
        m1=min(m1,x);
    }
    hash=tmp;

    tmp.clear();

    for (int i = 0; i < n; ++i) {
        cin>>x;
        // xorr=xorr^x;
        if(tmp.find(x)==tmp.end())
            tmp.insert(x);
        else {
            tmp.erase(x);
            s2.insert(x);
        }
        if(hash.find(x)==hash.end())
            hash.insert(x);
        else
            hash.erase(x);
        m2=min(m2,x);
    }


    if(hash.size()!=0){
        cout<<-1;
        return;
    }

    for(ll x:arr){
        auto it1 = s1.find(x);
        auto it2 = s2.find(x);
        if(it2 != s2.end()){
            s1.erase(it1);
            s2.erase(it2);
        }
    }

    auto p = s1.begin();
    auto q = s2.begin();

    // cout<<"s1 = ";
    // for(auto p:s1){
    //     cout<<p<<" ";
    // }
    // cout<<endl;

    ll nn = s1.size(), ans=0;

    if(m1 != m2){
        if(m1 < m2){
            ans += m1;
            p++;
        }
        else {
            ans += m2;
            q++;
        }
        nn--;
    }

    ll u = min(m1,m2);
    // cout<<"u = "<<u<<endl;
    // cout<<"nn = " << nn<<endl;

    for (int i = 0; i < nn and p!=s1.end() and q!=s2.end(); ++i) {
        if(*p < *q){
            ans += min(2*u,*p);
            p++;
        } else {
            ans += min(2*u,*q);
            q++;
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
