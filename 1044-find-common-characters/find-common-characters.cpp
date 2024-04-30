class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> hash(words.size(), vector<int>( 26, 0 ) );

        for ( int i=0; i<words.size(); i++ )
        {
            for ( int c : words[i] )
                hash[i][c - 'a']++;
        }

        vector<string> ans;

        for ( int i=0; i<26; i++ )
        {
            int mn = INT_MAX;

            for ( int j=0; j<words.size(); j++ )
                mn = min( mn, hash[j][i] );
            
            while ( mn-- )
                ans.push_back( string(1, i + 'a' ) );
        }

        return ( ans );

    }
};