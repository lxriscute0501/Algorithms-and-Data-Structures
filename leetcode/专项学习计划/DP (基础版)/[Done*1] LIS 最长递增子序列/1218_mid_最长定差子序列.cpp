class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            int n = arr.size();
            int dp[120001], ans = 0;
            for (int i = 1; i < 120000; i++)
            dp[i] = 0;
            dp[arr[0] + 100000] = 1;
            for (int i = 1; i < n; i++)
            {
                dp[arr[i] + 100000] = dp[arr[i] - difference + 100000] + 1;
            }
            for (int i = 0; i < n; i++)
            ans = max(ans, dp[arr[i] + 100000]);
            return ans;
        }
    };