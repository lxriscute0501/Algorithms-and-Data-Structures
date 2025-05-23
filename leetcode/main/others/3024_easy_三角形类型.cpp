class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c or a + c <= b or b + c <= a) return "none";
        else if (a == b and b == c) return "equilateral";
        else if (a == b or a == c or b == c) return "isosceles";
        else return "scalene";
    }
};