class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int n = matrix.size(), m = matrix[0].size(), sum = 2, x = 0, y = 0, idx = 0;
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
            bool b[11][11];
            for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            b[i][j] = true;
            b[0][0] = false;
            ans.push_back(matrix[0][0]);
            while (sum <= n * m)
            {
                if (x + dx[idx] < 0 or x + dx[idx] >= n or y + dy[idx] < 0 or y + dy[idx] >= m or !b[x + dx[idx]][y + dy[idx]]) {
                    idx = (idx + 1) % 4;
                    x += dx[idx];
                    y += dy[idx];
                } else {
                    x += dx[idx];
                    y += dy[idx];
                }
                ans.push_back(matrix[x][y]);
                sum ++;
                b[x][y] = false;
            }
            return ans;
        }
    };