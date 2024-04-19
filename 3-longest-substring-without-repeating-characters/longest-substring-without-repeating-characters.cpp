class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, length = 0;
        int i = 0;
        int alpha[256];
        int indices[256];
        
        memset(alpha, 0, 256 * sizeof(int));
        while (i < s.length())
        {
            if (alpha[s[i]] && indices[s[i]] >= start)
            {
                length = max(length, i - start);
                start = indices[s[i]] + 1;
                alpha[s[i]] = 0;
                i--;
            }
            else
            {
                indices[s[i]] = i;
                alpha[s[i]] = 1;
            }
            i++;
        }
        return (max(length, i - start));
    }
};