class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            int dp[1001];
    
            dp[1] = 0;
            dp[2] = min(cost[0], cost[1]);
    
            if (n == 2) return dp[2];
    
            for (int i=3; i<=n; i++)
            {
                dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
            }
            return dp[n];
        }
    };