class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k % n;
            int count = gcd(k, n);
            for (int i = 0; i < count; i++) 
            {
                int current = i;
                int prev = nums[i];
                do {
                    int next = (current + k) % n;
                    swap(nums[next], prev);
                    current = next;
                } while (i != current);
            }
        }
    };
    