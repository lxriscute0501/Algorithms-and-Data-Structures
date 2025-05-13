class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int ans1[n], ans2[n];
    
            int cnt=height[0];
            ans1[0] = 0;
            for (int i = 1; i < n; i++)
            {
                if (height[i] > cnt) {
                    ans1[i] = 0;
                    cnt = height[i];
                } else ans1[i] = cnt - height[i];
            }
    
            cnt = height[n - 1];
            ans2[n - 1] = 0;
            for (int i = n - 2; i >= 0; i--)
            {
                if (height[i] > cnt) {
                    ans2[i] = 0;
                    cnt = height[i];
                } else ans2[i] = cnt - height[i];
            }
    
            int ans = 0;
            for (int i = 0; i < n; i++)
            ans += min(ans1[i], ans2[i]);
    
            return ans;
        }
    };