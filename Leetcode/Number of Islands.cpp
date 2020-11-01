class Solution {
        int n, m;
        void dfs(int i, int j, vector<vector<char>>& grid) {
            if(i<0 or j<0 or i >= n or j >= m or grid[i][j] != '1')        return;
            grid[i][j] = '0';
            dfs(i + 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
            dfs(i - 1, j, grid);
        }
    public:
        int numIslands(vector<vector<char>>& grid) {
            int ans = 0;
            n = grid.size();
            if(n == 0)return 0;
            m = grid[0].size();
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == '1') {
                        dfs(i, j, grid);
                        ans++;
                    }
                }
            }
            return ans;
        }
};
