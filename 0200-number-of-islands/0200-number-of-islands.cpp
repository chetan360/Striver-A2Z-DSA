class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j, vector<vector<int>>& vis) {
        if(i>=m || j>=n || i<0 || j<0)
            return;
        if(vis[i][j] || grid[i][j]=='0')
            return;
        vis[i][j]=1;
        dfs(grid, m, n, i+1, j, vis);
        dfs(grid, m, n, i-1, j, vis);
        dfs(grid, m, n, i, j+1, vis);
        dfs(grid, m, n, i, j-1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<vector<int>> vis (m, vector<int>(n,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, m, n, i, j, vis);
                }
            }
        }

        return ans;
    }
};