class Solution {
    public:
        int minInsertions(string s) {
            int n = s.length();
            int dp[n][n];
    
            for (int i = n - 1; i >= 0; i--) 
            {
                dp[i][i] = 1;
                if (i < n - 1 and s[i] == s[i + 1]) dp[i][i + 1] = 2; 
                else if (i < n - 1) dp[i][i + 1] = 1;
    
                for (int j = i + 2; j < n; j++) 
                {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            return n - dp[0][n - 1];
        }
    };