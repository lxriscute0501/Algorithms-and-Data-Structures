class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            int dp[n][n];
    
            for (int i = n - 1; i >= 0; i--) 
            {
                dp[i][i] = 1;
                if (i < n - 1 and s[i] == s[i + 1]) dp[i][i + 1] = 2; 
                else if (i < n - 1) dp[i][i + 1] = 1;
                char c1 = s[i];
                for (int j = i + 2; j < n; j++) 
                {
                    char c2 = s[j];
                    if (c1 == c2) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[0][n - 1];
        }
    };
    