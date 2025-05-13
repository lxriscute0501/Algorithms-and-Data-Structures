class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n = haystack.size(), m = needle.size();
            if (m < 1) return 0;
            int next[m + 1];
            next[1] = 0;
            int k = 0;
            for (int i = 2; i <= m; i++)
            {
                while (k > 0 and needle[k] != needle[i - 1])
                k = next[k];
                if (needle[k] == needle[i - 1]) k ++;
                next[i] = k;
            }
            k = 0;
            for (int i = 1; i <= n; i++)
            {
                while (k > 0 and haystack[i - 1] != needle[k])
                k = next[k];
                if (haystack[i - 1] == needle[k]) k ++;
                if (k == m) return i - m;
            }
            return -1;
        }
    };