class Solution {
private:
    map<int, vector<int>> g;
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n);
        for(vector<int> edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            g[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        int visited = 0;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                visited++;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int child : g[node]) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    q.push(child);
                    visited++;
                }
            }
        }


        return visited == n;
    }
};
