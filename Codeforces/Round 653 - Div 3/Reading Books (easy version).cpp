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
    ll n,k;
    cin>>n>>k;
    ll alice=0,bob=0;
    vector<ll> p,q,r;
    for (int i = 0; i < n; ++i) {
        ll t,a,b;
        cin>>t>>a>>b;
        if(a==1 and b==1){
            alice++;
            bob++;
            r.pb(t);
        }
        else if(a==1){
            p.pb(t);
            alice++;
        }
        else if(b==1){
            q.pb(t);
            bob++;
        }
    }

    if(alice<k || bob<k){
        cout<<-1;
        return 0;
    }

    // cout<<p.size()<<q.size()<<r.size();
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    ll i=0,h=0;
    ll ans=0;
    while(k>0 and i<p.size() and i<q.size()  and h<r.size()){
        if(p[i]+q[i]< r[h]){
            ans+=(p[i]+q[i]);
            i++;
        } else {
            ans+=r[h];
            h++;
        }
        k--;
    }
    if(k>0){
        if(i>=p.size() || i>=q.size()) {
            while(k--){
                ans += r[h++];
            }
        } else {
            while(k--){
                ans += (p[i]+q[i]);
                i++;
            }
        }
    }

    cout<<ans;


    return 0;
}