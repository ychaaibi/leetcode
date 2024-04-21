class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,0), upper(26,0);
        
        for ( int i=0; i<word.length(); i++ )
        {
            if ( isupper(word[i]))
                upper[word[i] - 'A'] = 1;
            else
                lower[word[i] - 'a'] = 1;
        }
        
        int ans = 0;
        for ( int i=0; i<26; i++ )
        {
            ans += (upper[i] and lower[i]);
        }
        return ( ans );
    }
};