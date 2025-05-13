class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            int dp[101];
            dp[1] = nums[0];
            if (n == 1) return nums[0];
            
            dp[2] = nums[1];
            if (n == 2) return max(nums[0], nums[1]);
    
            for (int i=3; i<=n; i++)
                for (int j=1; j<=i-2; j++)
                {
                    dp[i] = max(dp[i], dp[j] + nums[i-1]);
                    dp[i] = max(dp[i], dp[i-1]);
                }
            return dp[n];
        }
    };