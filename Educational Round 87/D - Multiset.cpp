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
#define vi  vector<int>


vi BIT;

void update(int i,int val){
    while(i<BIT.size()){
        BIT[i]+=val;
        i = i + (i&(-i));
    }
}

int query(int i){
    ll ans=0;
    while(i>0){
        ans += BIT[i];
        i = i - (i&(-i));
    }
    return ans;
}

int findKthElement(int k){
    int start=1;
    int end=BIT.size()-1;
    int ans=0;
    while(start<=end){
        ll mid=(start+end)>>1;
        if(query(mid)>=k){
            ans=mid;
            end=mid-1;
        } 
        else 
            start=mid+1;
        
    }
    return ans;
}

int main() { 
    sync;
    int n,q,x,k;
    cin>>n>>q;
    BIT.resize(n+1);
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    for(int x:v){
        update(x,1);
    }
    while(q--){ 
        cin>>k;
        if(k>=1){
            update(k,1);
        }
        else {
            k = abs(k);
            k = findKthElement(k);
            update(k,-1);
        }
    }

    int ans = findKthElement(1);
    cout<<ans;

    return 0;
}
