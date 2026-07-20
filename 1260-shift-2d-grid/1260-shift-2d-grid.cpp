class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElt = m*n;

        if(k>totalElt) k %= totalElt;
        if(k==0) return grid;
        
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int flatIdx = (i*n+j+k) % totalElt;
                int row = flatIdx / n;
                int col = flatIdx % n;
                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};