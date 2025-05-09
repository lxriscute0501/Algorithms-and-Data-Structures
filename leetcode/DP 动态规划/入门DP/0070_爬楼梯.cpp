class Solution {
    public:
        int climbStairs(int n) {
            int a, b, c;
            a = 1; b = 2;
            if (n <= 2) return n;

            for (int i = 3; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            
            return c;
        }
    };