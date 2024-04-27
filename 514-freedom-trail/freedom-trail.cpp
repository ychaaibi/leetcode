class Solution {
public:
    vector<vector<int>> indexes;
    int                 size;

    int steps( int start, int end ) { return ( min( max(end, start) - min(end, start), min(end, start) + size - max(end, start) ) + 1 ); }

    int findRotateSteps(string ring, string key) {
        indexes = vector<vector<int>>(26);
        size = ring.size();

        for ( int i=0; i<ring.size(); i++ )
            indexes[ring[i] - 'a'].push_back( i );

        vector<vector<int>> dp( key.size() );

        dp[0] = vector<int>( indexes[key[0] - 'a'].size() );

        for ( int i=0; i<indexes[key[0] - 'a'].size(); i++ )
            dp[0][i] = steps( 0, indexes[key[0] - 'a'][i] );

        for ( int i=1; i<key.length(); i++ )
        {
            dp[i] = vector<int>( indexes[key[i] - 'a'].size(), INT_MAX );

            for ( int j=0; j<dp[i].size(); j++ )
                for ( int k=0; k<dp[i - 1].size(); k++ )
                    dp[i][j] = min( dp[i][j], steps(indexes[key[i] - 'a'][j], indexes[key[i - 1] - 'a'][k]) + dp[i - 1][k] ) ;
        }

        return ( *min_element( dp.back().begin(), dp.back().end() ) );
    }
};