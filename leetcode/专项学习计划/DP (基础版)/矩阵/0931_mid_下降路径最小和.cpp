class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int f[101][101];
            int n = matrix.size();
            for (int i = 0; i < n; i++)
            f[0][i] = matrix[0][i];
            for (int i = 1; i < n; i++)
            {
                f[i][0] = min(f[i-1][0], f[i-1][1]) + matrix[i][0];
                f[i][n-1] = min(f[i-1][n-1], f[i-1][n-2]) + matrix[i][n-1];
                for (int j = 1; j < n-1; j++)
                f[i][j] = min(min(f[i-1][j-1], f[i-1][j]), f[i-1][j+1]) + matrix[i][j];
            }
            int x = 99999;
            for (int i = 0; i < n; i++)
            x = min(x, f[n-1][i]);
            return x;
        }
    };