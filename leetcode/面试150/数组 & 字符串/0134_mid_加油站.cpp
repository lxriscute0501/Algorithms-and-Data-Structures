class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            int k = 0;
    
            while (k < n)
            {
                int sum = 0, cnt = 0;
    
                while (cnt < n)
                {
                    int i = (k + cnt) % n;
                    sum += gas[i] - cost[i];
                    if (sum < 0) break;
                    cnt ++;
                }
    
                if (cnt == n) return k; else k = k + cnt + 1; // 不用模，因为超过n必然不成立
            }
    
            return -1;
        }
    };