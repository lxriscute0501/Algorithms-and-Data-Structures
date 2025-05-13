class Solution {
    public:
        string longestPalindrome(string s) {
            int ans = 0;
            string ss;
            if (s.length() == 1) return s;
            if (s.length() == 2) {
                if (s[0] == s[1]) return s; else {
                    ss = ""; ss += s[0]; return ss;
                }
            }
            for (int i = 1; i < s.length() - 1; i++)
            {
                int l = i-1, r = i+1, len = 1;
                while (l >= 0 and s[l] == s[i]) {
                    l --; len ++;
                }     
                while (r < s.length() and s[r] == s[i]) {
                    r ++; len ++;
                }
                while (l >= 0 and r < s.length() and s[l] == s[r]) 
                {
                    len += 2;
                    l --; r ++;
                } 
                if (len > ans) {
                    ans = len;
                    ss = "";
                    for (int j = l+1; j < r; j++)
                    ss += s[j];
                }
            }
            return ss;
        }
    };