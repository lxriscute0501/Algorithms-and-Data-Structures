class Solution {
    public:
        int jump(vector<int>& nums) {
            int dist = nums.size() - 1, step = 0;
            while (dist > 0)
            {
                for (int i = 0; i < dist; i++)
                if (nums[i] + i >= dist) {
                    dist = i;
                    step ++;
                    break;
                }
            }
            return step;
        }
    };