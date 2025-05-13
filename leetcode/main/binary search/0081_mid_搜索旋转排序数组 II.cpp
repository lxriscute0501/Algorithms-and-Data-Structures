class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            if (nums.size() == 0) return false;
            else if (nums.size() == 1) return nums[0] == target ? true : false;
            else {
                int l = 0, r = nums.size() - 1;
                while (l <= r) 
                {
                    int mid = (l + r) / 2;
                    if (nums[mid] == target) return true;
                    if (nums[0] <= nums[mid] and nums[mid] > nums[nums.size() - 1]) {
                        if (nums[0] <= target and target < nums[mid]) r = mid - 1;
                        else l = mid + 1;
                    } else if (nums[0] > nums[mid] and nums[mid] <= nums[nums.size() - 1]) {
                        if (nums[nums.size() - 1] >= target and target > nums[mid]) l = mid + 1;
                        else r = mid - 1;
                    }
                    else {
                        for (int i=0; i<nums.size(); i++)
                        if (nums[i] == target) return true;
                        return false; 
                    }
                }
            }
            return false;
        }
    };