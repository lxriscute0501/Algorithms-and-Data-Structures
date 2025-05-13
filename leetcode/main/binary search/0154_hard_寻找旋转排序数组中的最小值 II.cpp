class Solution {
    public:
        int findMin(vector<int>& nums) {
            int low = 0, high = nums.size() - 1;
            while (low < high) 
            {
                int mid = (high + low) / 2;
                if (nums[mid] < nums[high]) high = mid;
                else if (nums[mid] > nums[high]) low = mid + 1;
                else {
                    bool b = true;
                    for (int i = mid + 1; i < high; i++)
                    if (nums[i] != nums[mid]) {
                        b = false; break;
                    }
                    if (b) high = mid; else low = mid + 1;
                }
            }
            return nums[low];
        }
    };
    