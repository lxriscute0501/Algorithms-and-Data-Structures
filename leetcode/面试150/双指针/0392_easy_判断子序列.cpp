class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int s1 = 0, t1 = 0;
            if (s.length() == 0) return true;
    
            while (t1 < t.length())
            {
                if (s[s1] == t[t1]) {
                    s1 ++;
                    t1 ++;
                } else t1 ++;
                if (s1 == s.length()) return true;
            }
    
            return false;
        }
    };