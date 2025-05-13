class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if (nums.size() < 1) return vector<int>{-1, -1};
            if (nums.size() == 1) return target == nums[0] ? vector<int>{0, 0} : vector<int>{-1, -1};
    
            double minn = target - 0.5, maxx = target + 0.5;
            int l1 = 0, r1 = nums.size() - 1, l2 = 0, r2 = nums.size() - 1, mid1, mid2;
            while (l1 <= r1) {
                mid1 = (l1 + r1) / 2;
                if (nums[mid1] > minn) r1 = mid1 - 1; else l1 = mid1 + 1;
            }
            while (l2 <= r2) {
                mid2 = (l2 + r2) / 2;
                if (nums[mid2] > maxx) r2 = mid2 - 1; else l2 = mid2 + 1;
            }
            if (l1 > r2) return vector<int>{-1, -1}; else return vector<int>{l1, r2};
        }
    };