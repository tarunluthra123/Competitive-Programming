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
#define inf 1e5

vector<vector<ll>> g;
int n,q,u,v;
unordered_set<int> girls;
vector<bool> vis;
ll ans=inf;
vector<ll> dist;

void dfs(ll node,ll x){
    if(vis[node]){
        return;
    }
    dist[node]=x;
    vis[node]=1;
    for(auto child:g[node]){
        dfs(child,x+1);
    }
}

ll solve(){
    // for (int i = 0; i < g.size(); ++i) {
    //     cout<<i<<"->";
    //     for (int j = 0; j < g[i].size(); ++j) {
    //         cout<<g[i][j]<<" " ;
    //     }
    //     cout<<endl;
    // }
    vis.resize(n+1);
    dist.resize(n+1);
    dfs(1,0);
    ll minDist=inf;
    for(int i=0;i<dist.size();i++){
        if(girls.find(i)!=girls.end() and minDist>dist[i]){
            ans=i;
            minDist=dist[i];
        }
        // cout << dist[i] << " ";
    }
    return ans;
}

int main() { 
    sync;
    cin>>n;
    g.resize(n+1);
    for (int i = 0; i < n-1; ++i) {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin>>q;
    while(q--){
        cin>>u;
        girls.insert(u);
    }

    cout<<solve();

    return 0;
}
