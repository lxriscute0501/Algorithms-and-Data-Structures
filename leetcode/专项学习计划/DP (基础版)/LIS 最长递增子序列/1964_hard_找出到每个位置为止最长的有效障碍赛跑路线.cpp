class Solution {
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            int n = obstacles.size();
            int d[n + 1], len = 1;
            vector<int> ans(n);
            d[1] = obstacles[0];
            ans[0] = 1;
    
            for (int i = 1; i < n; i++)
            {
                if (obstacles[i] >= d[len]) {
                    len ++;
                    d[len] = obstacles[i];
                    ans[i] = len;
                } else {
                    int l = 1, r = len, mid;
                    while (l <= r)
                    {
                        mid = (l + r) / 2;
                        if (((mid > 1 and d[mid - 1] <= obstacles[i]) or mid == 1) and obstacles[i] < d[mid]) {
                            ans[i] = mid;
                            d[mid] = obstacles[i];
                            break;
                        } else if (d[mid] <= obstacles[i]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
            }
    
            return ans;
        }
    };