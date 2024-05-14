class Solution {
public:
    int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    int getMax( vector<vector<int>>& grid, int i, int j, int gold )
    {
        if ( i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() )
            return ( gold );

        if ( grid[i][j] == 0 )
            return ( gold );
        
        int save = grid[i][j], ans = 0;

        grid[i][j] = 0;

        for ( int k=0; k<4; k++ )
            ans = max(ans, getMax(grid, i + dirs[k][0], j + dirs[k][1], gold + save ) );

        grid[i][j] = save;
        return ( ans );
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        for ( int i=0; i<grid.size(); i++ )
            for ( int j=0; j<grid[0].size(); j++ )
                if ( grid[i][j] )
                    ans = max(ans, getMax(grid, i, j, 0) );

        return (ans);
    }
};