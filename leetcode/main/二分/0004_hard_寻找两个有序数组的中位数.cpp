class Solution {
    public:
        double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
            int n = a.size(), m = b.size();
            if (n > m) {
                return findMedianSortedArrays(b, a); // 确保 a 是较短的数组
            }
    
            int low = 0, high = n;
            while (low <= high) {
                int partitionA = (low + high) / 2;
                int partitionB = (n + m + 1) / 2 - partitionA;
    
                int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
                int minRightA = (partitionA == n) ? INT_MAX : a[partitionA];
    
                int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
                int minRightB = (partitionB == m) ? INT_MAX : b[partitionB];
    
                if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                    if ((n + m) % 2 == 0) {
                        return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                    } else {
                        return max(maxLeftA, maxLeftB);
                    }
                } else if (maxLeftA > minRightB) {
                    high = partitionA - 1;
                } else {
                    low = partitionA + 1;
                }
            }
    
            return 0.0;
        }
    };