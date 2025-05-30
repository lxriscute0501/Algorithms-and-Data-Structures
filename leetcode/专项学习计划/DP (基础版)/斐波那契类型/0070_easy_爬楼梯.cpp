class Solution {
    public:
        int climbStairs(int n) {
            int a[46];
            a[1] = 1; a[2] = 2;
            
            for (int i=3; i<=n; i++)
            a[i] = a[i-1] + a[i-2];

            return a[n];
        }
    };


class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c;
        for (int i = 1; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};