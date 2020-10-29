#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int dp[100001];

int dfs(int src) {
    if(dp[src] != -1) {
        return dp[src];
    }

    bool leafNode = true;
    int childAns = 0;
    for(int child : graph[src]) {
        leafNode = false;
        childAns = max(childAns, dfs(child));
    }

    return dp[src] = leafNode? 0 : 1+childAns;
}

int longestPath(int v) {
    int ans = 0;

    memset(dp,-1,sizeof dp);

    for (int i = 1; i <= v; ++i)
    {
        ans = max(ans, dfs(i));
    }
    return ans;
}


int main() {
    int v,e;
    cin>>v>>e;

    while(e--) {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    cout << longestPath(v) << "\n";

    return 0;
}