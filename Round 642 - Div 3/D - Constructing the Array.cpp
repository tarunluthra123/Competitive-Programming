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



class Functor{
public:
    bool operator()(const pii &a,const pii &b){
        if(a.ss-a.ff == b.ss-b.ff){
            return a.ss > b.ss;
        }
        return  a.ss-a.ff < b.ss-b.ff;
    }
};

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        ll n;
        cin>>n;
        vi v(n);
        ll s=0;
        ll e=n-1;

        ll counter=1;

        priority_queue<pii,vector<pii>,Functor> q;
        q.push({0,n-1});

        while(!q.empty()){
            pii top=q.top();
            q.pop();
            ll mid=(top.ff+top.ss)>>1;
            if(mid>=0 and mid<n and v[mid]==0){
                v[mid]=counter++;

                q.push({mid+1,top.ss});
                q.push({top.ff,mid-1});
            } else {
            }
        }



        for (int i = 0; i < n; ++i) {
            cout<<v[i] << " ";
        }
        cout<<endl;
    }

    return 0;
}
