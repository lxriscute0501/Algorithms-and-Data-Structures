class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int k = 0;
        while (k < strs[0].length())
        {
            char ss = strs[0][k];
            bool x = true;
            for (int i = 1; i < strs.size(); i++)
                if (strs[i][k] != ss) {
                    x = false;
                    break;
                } 
            if (x) { s += ss; k ++; } else return s;
        }
        return s;
    }
};