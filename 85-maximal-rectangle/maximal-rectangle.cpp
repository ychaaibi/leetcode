class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp( matrix.size(), vector<int>( matrix[0].size(), 0) );
        
        for ( int i=0; i<matrix.size(); i++ )
        {
            dp[i].back() = matrix[i].back() - '0';
            for ( int j=matrix[0].size() - 2; j>=0; j-- )
                dp[i][j] = ( dp[i][j + 1] + matrix[i][j] - '0' ) * ( matrix[i][j] == '1' );
        }
        
        int ans = 0;
        
        for ( int i=matrix.size() - 1; i>=0; i-- )
        {
            for ( int j=matrix[0].size() - 1; j>=0; j-- )
            {
                if ( matrix[i][j] == '0') continue ;
                
                int curr = dp[i][j];
                
                ans = max(dp[i][j], ans);
                
                for ( int k=i + 1; k<matrix.size(); k++ )
                {
                    if ( matrix[k][j] == '0' )
                        break ;
                    curr = min( curr, dp[k][j] );
                    ans = max( ans, curr * ( k - i + 1 ) );
                }
            }
        }
        return ( ans );
    }
};