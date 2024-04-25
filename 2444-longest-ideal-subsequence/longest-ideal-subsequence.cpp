class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp( 26, 0 );
        int         ans = 1;
        
        dp[s.back() - 'a'] = 1;
        
        for ( int i=s.length() - 2; i>=0; i-- )
        {
            dp[s[i] - 'a']++;
            for ( int c=max(int('a'), s[i] - k); c<=min(int('z'), s[i] + k); c++ )
                dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[c - 'a'] + 1 - (c == s[i]) );
        }
        
        for ( int i=0; i<26; i++ )
            ans = max(ans, dp[i]);
        return ( ans );
    }
};