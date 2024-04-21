class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int p1 = 0, p2 = 0;
        int ans = 0;
        
        while ( p2 < s.length() )
        {
            if ( maxCost < abs(s[p2] - t[p2]))
            {
                if ( p1 < p2 )
                    maxCost += abs(s[p1] - t[p1]);
                p1++;
                p2 = max(p2, p1);
                continue ;
            }
            maxCost -= abs(s[p2] - t[p2]);
            ans = max(ans, p2 - p1 + 1);
            p2++;
        }
        return ( ans );
    }
};