class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.size() < 1) return 0;
            int left = 0, right = nums.size() - 1;
    
            while (left < right)
            {
                while (right >= left and nums[right] == val) right --;
    
                if (right < left) return left;
                if (nums[left] == val) {
                    swap(nums[left], nums[right]);
                    right --;
                }
                
                left ++;
            }
            if (nums[left] == val) return left; else return left + 1;
        }
    };