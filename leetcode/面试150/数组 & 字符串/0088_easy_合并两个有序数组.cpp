class Solution {
    public:
        vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int len = nums1.size() - 1;
            m --; n --;
            while (n >= 0) 
            {
                while (m >= 0 and nums1[m] > nums2[n]) 
                {
                    swap(nums1[len], nums1[m]);
                    len --; m --;
                }
                swap(nums1[len], nums2[n]);
                len --; n --;
            }
            return nums1;
        }
    };
    