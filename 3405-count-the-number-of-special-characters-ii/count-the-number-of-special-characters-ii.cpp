class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,0), upper(26,0);
        
        for ( int i=0; i<word.length(); i++ )
        {
            
            if ( upper[toupper(word[i]) - 'A'] == -1 )
                continue ;
            
            if ( isupper(word[i]))
                upper[word[i] - 'A'] = 1;
            else
            {
                if ( upper[word[i] - 'a'])
                {
                    upper[word[i] - 'a'] = -1;
                    continue ;
                }
                lower[word[i] - 'a'] = 1;
            }
        }
        
        int ans = 0;
        for ( int i=0; i<26; i++ )
        {
            ans += (upper[i] == 1 and lower[i] == 1);
        }
        return ( ans );
    }
};