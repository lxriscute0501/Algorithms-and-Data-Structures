class Solution {
    public:
        int longestArithSeqLength(vector<int>& nums) {
            int m = -999, ans = -999;
            int f[501];
    
            for (int v : nums)
            m = max(m, v);
    
            for (int d = -m; d <= m; d++)
            {
                for (int i = 0; i <= 500; i++)
                f[i] = 0;
                for (int x : nums)
                if (x - d >= 0 and x - d <= m) f[x] = f[x - d] + 1; else f[x] = 1;
                for (int x : nums)
                ans = max(ans, f[x]);
            }
    
            return ans;
        }
    };