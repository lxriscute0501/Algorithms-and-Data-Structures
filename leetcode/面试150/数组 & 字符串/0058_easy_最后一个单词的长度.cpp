class Solution {
    public:
        int lengthOfLastWord(string s) {
            int index = s.size() - 1;
            while (s[index] == ' ') index--;
            int wordLength = 0;
            while (index >= 0 and s[index] != ' ') 
            {
                wordLength++;
                index--;
            }
            return wordLength;
        }
    };
    