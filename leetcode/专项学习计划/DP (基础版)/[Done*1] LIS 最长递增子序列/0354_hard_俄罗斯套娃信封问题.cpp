class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
                return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
            });
            int d[100001], len = 1;
            d[1] = envelopes[0][1];
            for (int i = 1; i < envelopes.size(); i++)
            {
                if (envelopes[i][1] > d[len] and envelopes[i][0] != envelopes[i - 1][0]) //贪心：相同weigh一定取height最小的
                {
                    len ++;
                    d[len] = envelopes[i][1];
                } else {
                    int l = 1, r = len, mid;
                    while (l <= r)
                    {
                        mid = (l + r) / 2;
                        if ((mid == 1 or (mid > 1 and d[mid - 1] < envelopes[i][1])) and envelopes[i][1] < d[mid]) {
                            d[mid] = envelopes[i][1];
                            break;
                        } else if (d[mid] <= envelopes[i][1]) l = mid + 1;
                        else r = mid - 1;
                    }
                }
            }
            return len;
        }
    };