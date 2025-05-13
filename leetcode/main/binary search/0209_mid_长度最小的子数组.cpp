class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int left = 0, right = 0, ans = 100001, sum = 0;
            while (right < nums.size())
            {
                sum += nums[right];
                while (sum >= target) {
                    ans = min(ans, right - left + 1);
                    sum -= nums[left];
                    left ++;
                }
                right ++;
            }
            if (ans == 100001) return 0; else return ans;
        }
    };