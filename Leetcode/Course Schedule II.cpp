class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> g;
        vector<int> indegree(numCourses);
        for(vector<int> edge: prerequisites){
            g[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            res.push_back(f);

            for(int child:g[f]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }

        if(res.size()<numCourses)
            return {};

        return res;
    }
};
