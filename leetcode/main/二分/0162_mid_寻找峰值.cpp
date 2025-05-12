class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int left = 0, right = nums.size() - 1;
    
            while (left < right) 
            {
                int mid = (right + left) / 2;
                // 如果 mid 不是峰值，且右侧元素更大，则峰值在右侧
                if (nums[mid] < nums[mid + 1]) {
                    left = mid + 1;
                } else {
                    // 否则，峰值在左侧或 mid 就是峰值
                    right = mid;
                }
            }
            // 当 left == right 时，找到峰值
            return left;
        }
    };