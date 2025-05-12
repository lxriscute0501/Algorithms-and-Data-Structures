class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int dist = nums.size() - 1;
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                if (nums[i] + i >= dist) dist = i; //贪心：下标越小越容易包括
            }
            return dist == 0;
        }
    };