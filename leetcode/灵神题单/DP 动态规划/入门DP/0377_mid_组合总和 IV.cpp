class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            if (nums.size() < 2) {
                if (nums[0] == target) return 1; else return 0;
            }
    
            sort(nums.begin(), nums.end());
            int dp[1001];
            dp[0] = 1;
    
            for (int i = 1; i <= target; i++)
            {
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] > i) break;
                    if (dp[i] <= INT_MAX - dp[i - nums[j]]) dp[i] += dp[i - nums[j]]; // 居然有INT_MAX的样例卡，丧心病狂
                }
            }
    
            return dp[target];
        }
    };