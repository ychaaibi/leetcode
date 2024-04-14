class Solution {
public:
    bool    check_valid(string& word, vector<string>& forbidden, int p1, int p2)
    {
        for (int i=0; i<min(10, p2 - p1 + 1); i++)
        {
            string targ = word.substr(p2 - i, i + 1);
            if (binary_search(forbidden.begin(), forbidden.end(), targ)) return (false);
        }
        return (true);
    }
    
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int ans = 0;
        int p1 = 0, p2 = 0;
        
        sort(forbidden.begin(), forbidden.end());
        
        while (p2 < word.length())
        {
            if (check_valid(word, forbidden, p1, p2)) ans = max(ans, p2++ - p1 + 1);
            while (!check_valid(word, forbidden, p1, p2))
            {
                p1++;
                p2 = max(p2, p1);
            }
        }
        return (ans);
    }
};