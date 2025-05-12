class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0, buyin = prices[0];
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] < prices[i - 1]) {
                    ans += prices[i - 1] - buyin;
                    buyin = prices[i];
                }
            }
            return ans + prices[(int)prices.size() - 1] - buyin;
        }
    };