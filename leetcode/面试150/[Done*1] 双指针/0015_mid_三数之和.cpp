class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> sum;
            sort(nums.begin(), nums.end());
            int n = nums.size();
    
            for (int i = 0; i < n - 2; i++) 
            {
                if (i > 0 and nums[i] == nums[i - 1]) continue; // 跳过重复的 nums[i]
                int l = i + 1, r = n - 1;
                while (l < r) 
                {
                    int total = nums[i] + nums[l] + nums[r];
                    if (total < 0) {
                        l ++;
                    } else if (total > 0) {
                        r --;
                    } else {
                        sum.push_back({nums[i], nums[l], nums[r]});
                        // 跳过重复的 nums[l]
                        while (l < r and nums[l] == nums[l + 1]) l ++;
                        // 跳过重复的 nums[r]
                        while (l < r and nums[r] == nums[r - 1]) r --;
                        l ++;
                        r --;
                    }
                }
            }
            return sum;
        }
    };