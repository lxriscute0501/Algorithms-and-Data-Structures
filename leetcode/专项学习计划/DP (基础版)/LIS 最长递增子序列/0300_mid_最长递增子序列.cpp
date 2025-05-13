class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            int d[n + 1], len = 1;
            d[1] = nums[0];
            for (int i = 1; i < n; i++)
            {
                if (nums[i] > d[len]) {
                    len ++;
                    d[len] = nums[i];
                } else {
                    int l = 1, r = len, mid;
                    while (l <= r)
                    {
                        mid = (l + r) / 2;
                        if (((mid > 1 and d[mid - 1] < nums[i]) or mid == 1) and nums[i] < d[mid]) {
                            d[mid] = nums[i];
                            break;
                        } else if (d[mid] <= nums[i]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
            }
            return len;
        }
    };