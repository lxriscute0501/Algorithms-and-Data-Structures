class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if (nums.size() == 0) return -1;
            else if (nums.size() == 1) return nums[0] == target ? 0 : -1;
            else {
                int l = 0, r = nums.size() - 1;
                while (l <= r) 
                {
                    int mid = (l + r) / 2;
                    if (nums[mid] == target) return mid;
                    if (nums[0] <= nums[mid]) {
                        if (nums[0] <= target and target < nums[mid]) r = mid - 1;
                        else l = mid + 1;
                    } else if (nums[mid] <= nums[nums.size() - 1]) {
                        if (nums[nums.size() - 1] >= target and target > nums[mid]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
            }
            return -1;
        }
    };