class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int f[201];
            f[0] = triangle[0][0];
            
            for (int i = 1; i < n; i++)
            {
                f[i] = f[i-1] + triangle[i][i];
                for (int j = i-1; j > 0; j--)
                    f[j] = min(f[j], f[j-1]) + triangle[i][j];
                f[0] += triangle[i][0];
            }
            int x = 99999999;
            for (int i = 0; i < n; i++)
            x = min(x, f[i]);
            return x;
        }
    };