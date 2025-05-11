class Solution {
    public:
        int countGoodStrings(int low, int high, int zero, int one) {
            int sum = 0;
            int dp[100001];
            dp[0] = 1;
            for (int i = 1; i <= high; i++)
            {
                dp[i] = 0;
                if (i >= zero) dp[i] += dp[i - zero];
                if (i >= one) dp[i] += dp[i - one];
                dp[i] %= 1000000007;
            }
    
            for (int i = low; i <= high; i++)
            {
                sum += dp[i];
                sum %= 1000000007;
            }
    
            return sum;
        }
    };