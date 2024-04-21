class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>> hash( grid[0].size(), vector<int>(10, 0) );
        vector<vector<int>> dp( grid[0].size(), vector<int>(10, 0) );
            
        for ( int j=0; j<grid[0].size(); j++ )
            for ( int i=0; i<grid.size(); i++ )
                hash[j][grid[i][j]]++;
        
        
        for ( int i=0; i<=9; i++ )
            dp[grid[0].size() - 1][i] = grid.size() - hash[grid[0].size() - 1][i];
        
        for ( int i=grid[0].size() - 2; i >= 0; i-- )
        {   
            for ( int n1=0; n1<=9; n1++ )
            {
                int mn = INT_MAX;
                for ( int n2=0; n2<=9; n2++ )
                {
                    if ( n1 == n2 )
                        continue ;
                    mn = min(mn, dp[i + 1][n2] + int(grid.size()) - hash[i][n1]);
                }
                dp[i][n1] = mn;
            }
        }
        
        int ans = INT_MAX;
        
        for ( int i=0; i<=9; i++ )
            ans = min(dp[0][i], ans);
        return (ans);
    }
};