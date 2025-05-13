class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int dp[101][101], m=grid.size(), n=grid[0].size();
    
            dp[0][0] = 1;
            if (grid[0][0] == 1 or grid[m-1][n-1] == 1) return 0;

            for (int i=1; i<n; i++)
            if (grid[0][i] == 0) dp[0][i] = dp[0][i-1]; else dp[0][i] = 0;

            for (int i=1; i<m; i++)
            if (grid[i][0] == 0) dp[i][0] = dp[i-1][0]; else dp[i][0] = 0;

            for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            if (grid[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1]; else dp[i][j] = 0;
            
            return dp[m-1][n-1];
        }
    };