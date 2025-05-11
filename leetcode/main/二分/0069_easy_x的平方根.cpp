class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0 or x == 1) return x;
            long long l = 1, r = x, mid;
    
            while (l <= r) 
            {
                mid = (l + r) / 2;
                if (mid * mid <= x and (mid + 1) * (mid + 1) > x) return mid;
                else if ((mid + 1) * (mid + 1) <= x) l = mid + 1;
                else if (mid * mid > x) r = mid - 1;
            } 
            
            return mid;
        }
    };