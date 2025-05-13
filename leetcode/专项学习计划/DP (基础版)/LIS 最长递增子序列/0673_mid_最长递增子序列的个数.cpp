class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            int dp[n+1], cnt[n+1];
    
            for (int i = 0; i < n; i++)
            {
                dp[i] = 1;
                cnt[i] = 0;
            }
            cnt[0] = 1;
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
    
                if (dp[i] == 1) {
                    cnt[i] = 1;
                    continue;
                }
    
                for (int j = 0; j < i; j++)
                {
                    if (dp[i] == dp[j] + 1 and nums[j] < nums[i]) cnt[i] += cnt[j];
                }
            }
            int x = 0, ans = 0;
            for (int i = 0; i < n; i++)
                x = max(x, dp[i]);
            for (int i = 0; i < n; i++)
                if (dp[i] == x) ans += cnt[i];
            return ans;
        }
    };