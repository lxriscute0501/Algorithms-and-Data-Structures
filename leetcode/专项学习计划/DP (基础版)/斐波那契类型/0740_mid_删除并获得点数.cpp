class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int a[10001];
            for (int i = 1; i <= 10000; i++)
            a[i] = 0;
            a[nums[0]] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                a[nums[i]] += nums[i];
            }
    
            int dp[20001];
            dp[1] = a[1];
            dp[2] = max(a[1], a[2]);
            for (int i = 3; i <= 10000; i++)
            {
                dp[i] = max(dp[i-1], dp[i-2] + a[i]);
            }
            return dp[10000];
        }
    };
    